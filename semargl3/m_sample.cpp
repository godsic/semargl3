
#include "m_sample.h"
#include "m_settings.h"
#include "n_data.h"
#include "n_probe.h"
#include "m_image.h"
#include "n_reader.h"
#include "n_vfft.h"
#include "n_txtwriter.h"

#include <vcclr.h>
#if _MSC_VER > 1499 // Visual C++ 2008 only
#include <msclr/marshal.h>
using namespace msclr::interop;
#endif 

mcSample::mcSample(void)
{
}

void mcSample::DoTRSandFRS()
{
	if (cProbe::isCreated == 0) return;
	if (cDataContainer::SimulationsData.m_IsLoaded == 0) return;
	long long plane = mcSettings::m_trAveragingPlane;

	// TRS
	cDataContainer::SimulationsData.Do2DAveraging(plane);
	mcImage::Draw2DTRS();
	// FRS
	cDataContainer::SimulationsData.Get2DFFTFromAveragedData();
	mcImage::Draw2DFRS();

}

void mcSample::LoadTheData()
{
	cReader::LoadOMFData(cDataContainer::m_pGroundStateFileName,
					 cDataContainer::m_pDynamicFileNames,
					 cDataContainer::m_nNumberOfDynamicFiles,
					 &cDataContainer::SimulationsData,
					 &cDataContainer::p_ExtractingMethod);
}

void mcSample::GenFFTWindow()
{
	if (cDataContainer::SimulationsData.m_IsLoaded == 0) return;
	long long size = cDataContainer::SimulationsData.s_params.m_NumberOfTimeSteps;
	double alpha = mcSettings::m_aoKeiserCoeff;
	long long type = mcSettings::m_aoFFTWindowType;
	cFFT::GenerateWindow(type, size, alpha);
}

void mcSample::SaveTRSToTextFile(System::String ^filename)
{
	System::String^ header = gcnew System::String("# 2D Profile of the time resolved signal\n# Plane:\t"); 
	switch(mcSettings::m_trAveragingPlane)
	{
	case 0:
		header = header + "XT\n";
		break;
	case 1:
		header = header + "YT\n";
		break;
	case 2:
		header = header + "ZT\n";
		break;
	}
	header = header + "# Magnetization component:\t";
	switch(cDataContainer::p_ExtractingMethod.m_MagnetizationComponent)
	{
	case 0:
		header = header + "Mx\n";
		break;
	case 1:
		header = header + "My\n";
		break;
	case 2:
		header = header + "Mz\n";
		break;
	}
	//convert String to char
	pin_ptr<const wchar_t> wch = PtrToStringChars(filename);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((filename->Length + 1) * 2);
	errno_t err = 0;
	char* cfilename = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cfilename, sizeInBytes,
					wch, sizeInBytes);


	wch = PtrToStringChars(header);
	convertedChars = 0;
	sizeInBytes = ((header->Length + 1) * 2);
	err = 0;
	char* cheader = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cheader, sizeInBytes,
					wch, sizeInBytes);
	// Save the file	
	long long sizex = cDataContainer::SimulationsData.m_asizeX;
	long long max_sizex = 0;
	long long max_sizet = mcSettings::m_etPointsT;
	switch(mcSettings::m_trAveragingPlane)
	{
	case 0:
		max_sizex = mcSettings::m_etPointsX;
		break;
	case 1:
		max_sizex = mcSettings::m_etPointsY;
		break;
	case 2:
		max_sizex = mcSettings::m_etPointsZ;
		break;
	}
	cTXTWriter::SaveToFile(&cDataContainer::SimulationsData.avgdata[0].Re,
		cDataContainer::SimulationsData.m_asizeX,
		cDataContainer::SimulationsData.m_asizeZ,
		1, 1,
		cDataContainer::SimulationsData.s_params.m_CellSizeX,
		cDataContainer::SimulationsData.s_params.m_StageTime,
		0, 0,
		max_sizex,
		max_sizet,
		1, 1,
		save_regime::A2D,
		save_datatype::CMPX_RE,
		cfilename,
		cheader);



}

void mcSample::SaveFRSToTextFile(System::String ^filename)
{
	System::String^ header = gcnew System::String("# 2D Profile of the fft of the time resolved signal\n# Plane:\t"); 
	switch(mcSettings::m_trAveragingPlane)
	{
	case 0:
		header = header + "XF\n";
		break;
	case 1:
		header = header + "YF\n";
		break;
	case 2:
		header = header + "ZF\n";
		break;
	}
	header = header + "# Magnetization component:\t";
	switch(cDataContainer::p_ExtractingMethod.m_MagnetizationComponent)
	{
	case 0:
		header = header + "Mx\n";
		break;
	case 1:
		header = header + "My\n";
		break;
	case 2:
		header = header + "Mz\n";
		break;
	}
	//convert String to char
	pin_ptr<const wchar_t> wch = PtrToStringChars(filename);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((filename->Length + 1) * 2);
	errno_t err = 0;
	char* cfilename = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cfilename, sizeInBytes,
					wch, sizeInBytes);


	wch = PtrToStringChars(header);
	convertedChars = 0;
	sizeInBytes = ((header->Length + 1) * 2);
	err = 0;
	char* cheader = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cheader, sizeInBytes,
					wch, sizeInBytes);
	// Save the file	
	long long sizex = cDataContainer::SimulationsData.m_asizeX;
	long long max_sizex = 0;
	long long max_sizet = mcSettings::m_etPointsT;
    double cs_x = 0.0F;
	switch(mcSettings::m_trAveragingPlane)
	{
	case 0:
		max_sizex = mcSettings::m_etPointsX;
		cs_x = cDataContainer::SimulationsData.s_params.m_CellSizeX;
		break;
	case 1:
		max_sizex = mcSettings::m_etPointsY;
		cs_x = cDataContainer::SimulationsData.s_params.m_CellSizeY;
		break;
	case 2:
		max_sizex = mcSettings::m_etPointsZ;
		cs_x = cDataContainer::SimulationsData.s_params.m_CellSizeZ;
		break;
	}
	cTXTWriter::SaveToFile(&cDataContainer::SimulationsData.avgdata_fft[0].Re,
		cDataContainer::SimulationsData.m_asizeX,
		cDataContainer::SimulationsData.m_asizeZ,
		1, 1,
		cs_x,
		cDataContainer::SimulationsData.s_params.m_StageTime,
		0, 0,
		max_sizex,
		max_sizet,
		1, 1,
		save_regime::A2D,
		save_datatype::CMPX_AP,
		cfilename,
		cheader);	
}
void mcSample::Save2DToTextFile(System::String^ filename, System::String^ header, long long mode)
{
    //convert String to char
	pin_ptr<const wchar_t> wch = PtrToStringChars(filename);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((filename->Length + 1) * 2);
	errno_t err = 0;
	char* cfilename = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cfilename, sizeInBytes,
					wch, sizeInBytes);


	wch = PtrToStringChars(header);
	convertedChars = 0;
	sizeInBytes = ((header->Length + 1) * 2);
	err = 0;
	char* cheader = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cheader, sizeInBytes,
					wch, sizeInBytes);
	// Save the file	
	long long sizex = cDataContainer::SimulationsData.m_lsizeX;
	long long sizey = cDataContainer::SimulationsData.m_lsizeY;
	long long max_sizex = 0;
	long long max_sizey = 0;

	double cs_x = 0;
	double cs_y = 0;

	long long regime = 0;
	switch(mcSettings::m_mmdMode)
	{
	case 0:
		// Re and Img
		switch (mode)
		{
		case 0:
			// Re
			regime = save_datatype::CMPX_RE;
			break;
		case 1:
			// Img
			regime = save_datatype::CMPX_IMG;
			break;
		case 2:
			// Re plus Img
			regime = save_datatype::CMPX;
			break;
		}
		break;
	case 1:
		// Amp and Phase
		switch (mode)
		{
		case 0:
			// Amp
			regime = save_datatype::CMPX_AP;
			break;
		case 1:
			// Phs
			regime = save_datatype::CMPX_AP;
			break;
		case 2:
			// Amp plus Phs
			regime = save_datatype::CMPX_AP;
			break;
		}
		break;
	}
	switch(mcSettings::m_mmdProjType)
	{
	case 0:
		// XY
		max_sizex = mcSettings::m_etPointsX;
		max_sizey = mcSettings::m_etPointsY;
		cs_x = cDataContainer::SimulationsData.s_params.m_CellSizeX;
		cs_y = cDataContainer::SimulationsData.s_params.m_CellSizeY;
		break;
	case 1:
		// XZ
		max_sizex = mcSettings::m_etPointsX;
		max_sizey = mcSettings::m_etPointsZ;
		cs_x = cDataContainer::SimulationsData.s_params.m_CellSizeX;
		cs_y = cDataContainer::SimulationsData.s_params.m_CellSizeZ;
		break;
	case 2:
		// YZ
		max_sizex = mcSettings::m_etPointsY;
		max_sizey = mcSettings::m_etPointsZ;
		cs_x = cDataContainer::SimulationsData.s_params.m_CellSizeY;
		cs_y = cDataContainer::SimulationsData.s_params.m_CellSizeZ;
		break;
	}
	cTXTWriter::SaveToFile(&cDataContainer::SimulationsData.layer_buff_2d[0].Re,
		cDataContainer::SimulationsData.m_lsizeX,
		cDataContainer::SimulationsData.m_lsizeY,
		1, 1,
		cs_x,
		cs_y,
		0, 0,
		max_sizex,
		max_sizey,
		1, 1,
		save_regime::A2D,
		regime,
		cfilename,
		cheader);

}
void mcSample::Save3DToTextFile(System::String^ filename, System::String^ header, long long mode)
{
    //convert String to char
	pin_ptr<const wchar_t> wch = PtrToStringChars(filename);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((filename->Length + 1) * 2);
	errno_t err = 0;
	char* cfilename = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cfilename, sizeInBytes,
					wch, sizeInBytes);


	wch = PtrToStringChars(header);
	convertedChars = 0;
	sizeInBytes = ((header->Length + 1) * 2);
	err = 0;
	char* cheader = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cheader, sizeInBytes,
					wch, sizeInBytes);
	// Save the file	
	long long sizex = cDataContainer::SimulationsData.m_lsizeX;
	long long siezy = cDataContainer::SimulationsData.m_lsizeY;
	long long sizez = cDataContainer::SimulationsData.m_lsizeZ;

	long long max_sizex = 0;
	long long max_sizey = 0;
	long long max_sizez = 0;

	double cs_x = 0.0;
	double cs_y = 0.0;
	double cs_z = 0.0;

	long long regime = 0;
	switch(mcSettings::m_mmdMode)
	{
	case 0:
		// Re and Img
		switch (mode)
		{
		case 0:
			// Re
			regime = save_datatype::CMPX_RE;
			break;
		case 1:
			// Img
			regime = save_datatype::CMPX_IMG;
			break;
		case 2:
			// Re plus Img
			regime = save_datatype::CMPX;
			break;
		}
		break;
	case 1:
		// Amp and Phase
		switch (mode)
		{
		case 0:
			// Amp
			regime = save_datatype::CMPX_AP;
			break;
		case 1:
			// Phs
			regime = save_datatype::CMPX_AP;
			break;
		case 2:
			// Amp plus Phs
			regime = save_datatype::CMPX_AP;
			break;
		}
		break;
	}
	max_sizex = mcSettings::m_etPointsX;
	max_sizey = mcSettings::m_etPointsY;
	max_sizez = mcSettings::m_etPointsZ;

	cs_x = cDataContainer::SimulationsData.s_params.m_CellSizeX;
	cs_y = cDataContainer::SimulationsData.s_params.m_CellSizeY;
	cs_z = cDataContainer::SimulationsData.s_params.m_CellSizeZ;

	cTXTWriter::SaveToFile(&cDataContainer::SimulationsData.layer_buff_3d[0].Re,
		cDataContainer::SimulationsData.m_lsizeX,
		cDataContainer::SimulationsData.m_lsizeY,
		cDataContainer::SimulationsData.m_lsizeZ, 1,
		cs_x,
		cs_y,
		cs_z, 0,
		max_sizex,
		max_sizey,
		max_sizez, 1,
		save_regime::A3D,
		regime,
		cfilename,
		cheader);

}
void mcSample::DrawMagnetization()
{
	long long time = mcSettings::m_mmdStepi;
	long long depth = mcSettings::m_mmdDepthi;
	long long plane = mcSettings::m_mmdProjType;
	cDataContainer::SimulationsData.Get2DSpatialLayer(plane,time,depth);
	mcImage::Draw2DMagRe();
	mcImage::Draw2DMagImg();
}

void mcSample::Get3DMode()
{
	long long time = mcSettings::m_mmdStepi;
	cDataContainer::SimulationsData.Get3DSpatialLayer(time);
}

void mcSample::Delete3DMode()
{
	cDataContainer::SimulationsData.Destroy3DLayerBuffer();
}

void mcSample::DoSpectrum()
{
	long long avgmethod = mcSettings::m_fdaAvgMethod;
	switch(mcSettings::m_fdaMethod)
	{
	case 0:
		cDataContainer::SimulationsData.DoF2A(avgmethod);
		break;
	case 1:
		cDataContainer::SimulationsData.DoA2F();
		break;
	case 2:
		cDataContainer::SimulationsData.DoFF2A();
		break;
	}
}

void mcSample::SaveSpectrumToTextFile(System::String ^filename)
{
	// Generate header
	System::String^ header = gcnew System::String("# SEMARGL3 OUTPUT:\n");
	header += L"# Spectrum of magnetization dynamics\n";
	header += L"# METHOD:\t";
	switch(mcSettings::m_fdaMethod)
	{
	case 0:
		// F2A
		header += L"F2A\n";
		break;
	case 1:
		// A2F
		header += L"A2F\n";
		break;
	}
	header += L"# COMPONENT:\t";
	switch(cDataContainer::p_ExtractingMethod.m_MagnetizationComponent)
	{
	case 0:
		// Mx
		header += L"Mx";
		break;
	case 1:
		// My
		header += L"My";
		break;
	case 2:
		// Mz
		header += L"Mz";
		break;
	}
	header += L"# MODE:\t";
	long long mode = 0;
	if (mcSettings::m_fdaAvgMethod == 0)
	{
		switch(mcSettings::m_fdaMode)
		{
		case 0:
			// Re and Img
			header += L"Re; Im\n";
			mode = save_datatype::CMPX;
			break;
		case 1:
			// Amp and Phase
			header += L"Amp; Phase\n";
			mode = save_datatype::CMPX_AP;
			break;
		}
	}
	else
	{
		header += L"Amp; Phase\n";
		mode = save_datatype::CMPX;
	}

	pin_ptr<const wchar_t> wch = PtrToStringChars(filename);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((filename->Length + 1) * 2);
	errno_t err = 0;
	char* cfilename = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cfilename, sizeInBytes,
					wch, sizeInBytes);


	wch = PtrToStringChars(header);
	convertedChars = 0;
	sizeInBytes = ((header->Length + 1) * 2);
	err = 0;
	char* cheader = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cheader, sizeInBytes,
					wch, sizeInBytes);

	long long sizex = cDataContainer::SimulationsData.s_params.m_NumberOfTimeSteps / 2;
	long long cs_x  = cDataContainer::SimulationsData.s_params.m_ResFrequency;
	long long max_sizex = mcSettings::m_etPointsT / 2;

	cTXTWriter::SaveToFile(&cDataContainer::SimulationsData.avgdata[0].Re,
		sizex,
		1, 1, 1,
		cs_x,
		0, 0, 0,
		max_sizex,
		1, 1, 1,
		save_regime::A1D,
		mode,
		cfilename,
		cheader);
}
void mcSample::SaveSpectrumToTextFileN(char* cfilename)
{
	// Generate header
	System::String^ header = gcnew System::String("# SEMARGL3 OUTPUT:\n");
	header += L"# Spectrum of magnetization dynamics\n";
	header += L"# METHOD:\t";
	switch(mcSettings::m_fdaMethod)
	{
	case 0:
		// F2A
		header += L"F2A\n";
		break;
	case 1:
		// A2F
		header += L"A2F\n";
		break;
	}
	header += L"# COMPONENT:\t";
	switch(cDataContainer::p_ExtractingMethod.m_MagnetizationComponent)
	{
	case 0:
		// Mx
		header += L"Mx";
		break;
	case 1:
		// My
		header += L"My";
		break;
	case 2:
		// Mz
		header += L"Mz";
		break;
	}
	header += L"# MODE:\t";
	long long mode = 0;
	if (mcSettings::m_fdaAvgMethod == 0)
	{
		switch(mcSettings::m_fdaMode)
		{
		case 0:
			// Re and Img
			header += L"Re; Im\n";
			mode = save_datatype::CMPX;
			break;
		case 1:
			// Amp and Phase
			header += L"Amp; Phase\n";
			mode = save_datatype::CMPX_AP;
			break;
		}
	}
	else
	{
		header += L"Amp; Phase\n";
		mode = save_datatype::CMPX;
	}

	pin_ptr<const wchar_t> wch = PtrToStringChars(header);
	size_t convertedChars = 0;
	size_t sizeInBytes = ((header->Length + 1) * 2);
	errno_t err = 0;
	char* cheader = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cheader, sizeInBytes,
					wch, sizeInBytes);

	long long sizex = cDataContainer::SimulationsData.s_params.m_NumberOfTimeSteps / 2;
	long long cs_x  = cDataContainer::SimulationsData.s_params.m_ResFrequency;
	long long max_sizex = mcSettings::m_etPointsT / 2;

	cTXTWriter::SaveToFile(&cDataContainer::SimulationsData.avgdata[0].Re,
		sizex,
		1, 1, 1,
		cs_x,
		0, 0, 0,
		max_sizex,
		1, 1, 1,
		save_regime::A1D,
		mode,
		cfilename,
		cheader);
}

void mcSample::Do3DDispersion()
{
	cDataContainer::SimulationsData.Get4DFFT();
}

void mcSample::GetSliceOf3DDispersion()
{
	long long isAvgX = mcSettings::m_dcIsAvgX;
	long long isAvgY = mcSettings::m_dcIsAvgY;
	long long isAvgZ = mcSettings::m_dcIsAvgZ;

	long long AvgMX = mcSettings::m_dcAvgMethodX;
	long long AvgMY = mcSettings::m_dcAvgMethodY;
	long long AvgMZ = mcSettings::m_dcAvgMethodZ;

	long long coordx = mcSettings::m_dcProbeXi;
	long long coordy = mcSettings::m_dcProbeYi;
	long long coordz = mcSettings::m_dcProbeZi;
	cDataContainer::SimulationsData.Get4DFFTVolumeSlice(isAvgX, isAvgY, isAvgZ, AvgMX, AvgMY, AvgMZ, coordx, coordy, coordz);
}

void mcSample::DrawDispersionSlice()
{
	mcImage::Draw2DDispersionSlice();
}

void mcSample::SaveDispersionToTextFile(System::String^ filename)
{
	// Generate header
	long long isXfixed = 0;
	long long isYfixed = 0;
	long long isZfixed = 0;

	System::String^ header = gcnew System::String("# SEMARGL3 OUTPUT:\n");
	header += L"# Dispersion of the Magnetization dynamics\n";
	header += L"# METHOD:\t";
	if (mcSettings::m_dcIsAvgX == 1)
	{
		switch(mcSettings::m_dcAvgMethodX)
		{
		case 0:
			header += L"X: CA";
			return;
		case 1:
			header += L"X: CAA";
			break;
		}
	}
	else
	{
		if (mcSettings::m_dcProbeXf < 0)
		{
			header += "X: FIXED\t";
			isXfixed = 1;
		}
		else header += "X: kx = " + System::Convert::ToString(mcSettings::m_dcProbeXf) + " m^-1\t";
	}

	if (mcSettings::m_dcIsAvgY == 1)
	{
		switch(mcSettings::m_dcAvgMethodY)
		{
		case 0:
			header += L"Y: CA\t";
			return;
		case 1:
			header += L"Y: CAA\t";
			break;
		}
	}
	else
	{
		if (mcSettings::m_dcProbeYf < 0)
		{
			header += "Y: FIXED\t";
			isYfixed = 1;
		}
		else header += "Y: ky = " + System::Convert::ToString(mcSettings::m_dcProbeYf) + " m^-1\t";
	}

	if (mcSettings::m_dcIsAvgZ == 1)
	{
		switch(mcSettings::m_dcAvgMethodZ)
		{
		case 0:
			header += L"Z: CA\n";
			return;
		case 1:
			header += L"Z: CAA\n";
			break;
		}
	}
	else
	{
		if (mcSettings::m_dcProbeZf < 0)
		{
			header += "Z: FIXED\n";
			isZfixed = 1;
		}
		else header += "Z: kz = " + System::Convert::ToString(mcSettings::m_dcProbeZf) + " m^-1\n";
	}

	header += L"# COMPONENT:\t";
	switch(cDataContainer::p_ExtractingMethod.m_MagnetizationComponent)
	{
	case 0:
		// Mx
		header += L"Mx";
		break;
	case 1:
		// My
		header += L"My";
		break;
	case 2:
		// Mz
		header += L"Mz";
		break;
	}
	header += L"# MODE:\t";
	long long mode = 0;
	if (mcSettings::m_dcAvgMethodX == 0 && mcSettings::m_dcAvgMethodY == 0 && mcSettings::m_dcAvgMethodZ == 0 )
	{
		switch(mcSettings::m_dcMode)
		{
		case 0:
			// Re and Img
			header += L"Re; Im\n";
			mode = save_datatype::CMPX;
			break;
		case 1:
			// Amp and Phase
			header += L"Amp; Phase\n";
			mode = save_datatype::CMPX_AP;
			break;
		}
	}
	else
	{
		header += L"Amp; Phase\n";
		mode = save_datatype::CMPX;
	}

	pin_ptr<const wchar_t> wch = PtrToStringChars(filename);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((filename->Length + 1) * 2);
	errno_t err = 0;
	char* cfilename = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cfilename, sizeInBytes,
					wch, sizeInBytes);


	wch = PtrToStringChars(header);
	convertedChars = 0;
	sizeInBytes = ((header->Length + 1) * 2);
	err = 0;
	char* cheader = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, 
					cheader, sizeInBytes,
					wch, sizeInBytes);

	long long size  = 0;
	long long sizet  = cDataContainer::SimulationsData.m_asizeT;
	long long max_size = 0;
	float cs_r = 0.0;

	if (isXfixed == 1 )
	{
		size = cDataContainer::SimulationsData.m_asizeX;
		cs_r = cProbe::m_multResInverseWavelengthX;
		max_size = mcSettings::m_etPointsX;
	}
	if (isYfixed == 1 )
	{
		size = cDataContainer::SimulationsData.m_asizeY;
		cs_r = cProbe::m_multResInverseWavelengthY;
		max_size = mcSettings::m_etPointsY;
	}
	if (isZfixed == 1 )
	{
		size = cDataContainer::SimulationsData.m_asizeZ;
		cs_r = cProbe::m_multResInverseWavelengthZ;
		max_size = mcSettings::m_etPointsZ;
	}

	float cs_t = (float)cDataContainer::SimulationsData.s_params.m_ResFrequency;
	float max_sizet = (float)mcSettings::m_etPointsT; 
	cTXTWriter::SaveToFile(&cDataContainer::SimulationsData.avgdata_fft[0].Re,
		size, sizet,
		1, 1,
		cs_r, cs_t,
		0, 0,
		max_size, max_sizet,
		1, 1,
		save_regime::A2D,
		mode,
		cfilename,
		cheader);

}

void mcSample::GetMultipoleExpansion(System::String^% text)
{
	double *Qm;
	double *Qd;
	double *Qq;

	long long *Sm = new long long;
	long long *Sd = new long long;
	long long *Sq = new long long;
	long long t = mcSettings::m_mmdStepi;

	text += "semargl3 multipole expansion engine:\n";
	text += "Mode's frequency:\t"+System::Convert::ToString(mcSettings::m_mmdStepf) + " Hz\n";

	// monopole
	text += "\n";
	cDataContainer::SimulationsData.GetMultipoleCoeff(t, 0LL, &Qm, &Sm);
	text += "qtot:\t" + System::Convert::ToString(Qm[0]);

	// dipole
	text += "\n\n";
	cDataContainer::SimulationsData.GetMultipoleCoeff(t, 1LL, &Qd, &Sd);	
	text += "Px:\t" + System::Convert::ToString(Qd[0]) + "\n";
	text += "Py:\t" + System::Convert::ToString(Qd[1]) + "\n";
	text += "Pz:\t" + System::Convert::ToString(Qd[2]) + "\n";

	// quadrupole
	text += "\n";
	cDataContainer::SimulationsData.GetMultipoleCoeff(t, 2LL, &Qq, &Sq);	
	text += "Qxx:\t" + System::Convert::ToString(Qq[0]) + "\n";
	text += "Qxy:\t" + System::Convert::ToString(Qq[1]) + "\n";
	text += "Qxz:\t" + System::Convert::ToString(Qq[2]) + "\n";
	text += "Qyx:\t" + System::Convert::ToString(Qq[3]) + "\n";
	text += "Qyy:\t" + System::Convert::ToString(Qq[4]) + "\n";
	text += "Qyz:\t" + System::Convert::ToString(Qq[5]) + "\n";
	text += "Qzx:\t" + System::Convert::ToString(Qq[6]) + "\n";
	text += "Qzy:\t" + System::Convert::ToString(Qq[7]) + "\n";
	text += "Qzz:\t" + System::Convert::ToString(Qq[8]) + "\n";
}

long long mcSample::DoBatch()
{
	cDataContainer::m_pGroundStateFileName = mcSettings::m_dpStaticFileName;
	cDataContainer::m_pDynamicFilesFolder = mcSettings::m_dpDataFolder;
	cDataContainer::m_pDynamicFileNames = mcSettings::m_dpDataFileNames;
	cDataContainer::m_nNumberOfDynamicFiles = mcSettings::m_dpFilesCount;
	cDataContainer::p_ExtractingMethod.m_MagnetizationComponent = mcSettings::m_dpMagnetization;
	cDataContainer::p_ExtractingMethod.m_PreprocessingMethod = mcSettings::m_dpPreProcMethod;
	cDataContainer::p_ExtractingMethod.m_IsNormaliseByMs = 1;
	
	System::Console::Write("Extracting parameters of the simulations...");
	/*long long error = cReader::ProbeParametersOfSimulations(cDataContainer::m_pGroundStateFileName,
																cDataContainer::m_pDynamicFileNames, 
																cDataContainer::m_nNumberOfDynamicFiles,
																&cDataContainer::SimulationsData);*/
	long long error = cReader::ProbeParametersOfSimulations(mcSettings::m_dpStaticFileName,
																mcSettings::m_dpDataFileNames, 
																mcSettings::m_dpFilesCount,
																&cDataContainer::SimulationsData);
	if (error == 0 ) cDataContainer::SimulationsData.SetParametersFlag();
	else 
	{
		System::Console::WriteLine("Error!");
		return 1;
	}
	System::Console::WriteLine("Done.");

	System::Console::Write("Allocating memory buffers...");
	cDataContainer::SimulationsData.AllocateBuffers();
	System::Console::WriteLine("Done.");

	System::Console::Write("Loading data...");

	error = cReader::LoadOMFData(cDataContainer::m_pGroundStateFileName,
					 cDataContainer::m_pDynamicFileNames,
					 cDataContainer::m_nNumberOfDynamicFiles,
					 &cDataContainer::SimulationsData,
					 &cDataContainer::p_ExtractingMethod);
	if (error == 0) System::Console::WriteLine("Done.");
	else
	{
		System::Console::WriteLine("Error!");
		return 1;
	}
	mcSettings::m_etPointsX = cDataContainer::SimulationsData.s_params.m_SizeX;
	mcSettings::m_etPointsY = cDataContainer::SimulationsData.s_params.m_SizeY;
	mcSettings::m_etPointsZ = cDataContainer::SimulationsData.s_params.m_SizeZ;
	mcSettings::m_etPointsT = cDataContainer::SimulationsData.s_params.m_NumberOfTimeSteps;
	cProbe::Reset();

	System::Console::Write("Generating Probe...");
	if (mcSettings::m_pbX0 == -1) mcSettings::m_pbX0 = 0;
	double x0_m = mcSettings::m_pbX0 * cDataContainer::SimulationsData.s_params.m_CellSizeX;
	cProbe::X0 = mcSettings::m_pbX0;
	cProbe::X0_m = x0_m;
	if (mcSettings::m_pbX1 == -1) mcSettings::m_pbX1 = cDataContainer::SimulationsData.s_params.m_SizeX;
	double x1_m = mcSettings::m_pbX1 * cDataContainer::SimulationsData.s_params.m_CellSizeX;
	cProbe::X1 = mcSettings::m_pbX1;
	cProbe::X1_m = x1_m;

	if (mcSettings::m_pbY0 == -1) mcSettings::m_pbY0 = 0;
	double y0_m = mcSettings::m_pbY0 * cDataContainer::SimulationsData.s_params.m_CellSizeY;
	cProbe::Y0 = mcSettings::m_pbY0;
	cProbe::Y0_m = y0_m;
	if (mcSettings::m_pbY1 == -1) mcSettings::m_pbY1 = cDataContainer::SimulationsData.s_params.m_SizeY;
	double y1_m = mcSettings::m_pbY1 * cDataContainer::SimulationsData.s_params.m_CellSizeY;
	cProbe::Y1 = mcSettings::m_pbY1;
	cProbe::Y1_m = y1_m;

	if (mcSettings::m_pbZ0 == -1) mcSettings::m_pbZ0 = 0;
	double z0_m = mcSettings::m_pbZ0 * cDataContainer::SimulationsData.s_params.m_CellSizeZ;
	cProbe::Z0 = mcSettings::m_pbZ0;
	cProbe::Z0_m = z0_m;
	if (mcSettings::m_pbZ1 == -1) mcSettings::m_pbZ1 = cDataContainer::SimulationsData.s_params.m_SizeZ;
	double z1_m = mcSettings::m_pbZ1 * cDataContainer::SimulationsData.s_params.m_CellSizeZ;
	cProbe::Z1 = mcSettings::m_pbZ1;
	cProbe::Z1_m = z1_m;


	cProbe::sizeX = System::Math::Abs(cProbe::X0 - cProbe::X1);
	cProbe::sizeX_m = cProbe::sizeX * cDataContainer::SimulationsData.s_params.m_CellSizeX;

	cProbe::sizeY = System::Math::Abs(cProbe::Y0 - cProbe::Y1);
	cProbe::sizeY_m = cProbe::sizeY * cDataContainer::SimulationsData.s_params.m_CellSizeY;

	cProbe::sizeZ = System::Math::Abs(cProbe::Z0 - cProbe::Z1);
	cProbe::sizeZ_m = cProbe::sizeZ * cDataContainer::SimulationsData.s_params.m_CellSizeZ;
	long long fsizeX = cDataContainer::SimulationsData.s_params.m_SizeX;
	long long fsizeY = cDataContainer::SimulationsData.s_params.m_SizeY;
	long long fsizeZ = cDataContainer::SimulationsData.s_params.m_SizeZ;
	double csx = cDataContainer::SimulationsData.s_params.m_CellSizeX;
	double csy = cDataContainer::SimulationsData.s_params.m_CellSizeY;
	double csz = cDataContainer::SimulationsData.s_params.m_CellSizeZ;

	cProbe::Create(fsizeX, fsizeY, fsizeZ, csx, csy, csz);
	System::Console::WriteLine("Done.");
	System::Console::Write("Generating DFT window...");
	mcSample::GenFFTWindow();
	System::Console::WriteLine("Done.");
	// Do the processing

	switch (mcSettings::m_clMode)
	{
	case 0:
		//spectral
		System::Console::Write("Do spectral analysis...");
		DoSpectrum();
		System::Console::WriteLine("Done.");
		System::Console::Write("Saving result...");
		SaveSpectrumToTextFileN(mcSettings::m_dpOut);
		System::Console::WriteLine("Done.");
		break;
	case 1:
		//dispersion
		break;
	}

	/*System::Console::Write("Destroying memory buffers...");
	delete cDataContainer::SimulationsData;
	System::Console::WriteLine("Done.");*/

	return 0;
}

void mcSample::GetModeWaveVectors(System::String^% text)
{
	Get3DMode();
	cDataContainer::SimulationsData.Get3DModeWaveNumber();

	text += "# Mode wave vector (wave number)\n";
	text += "# kx(nx):\t" + System::Convert::ToString(cDataContainer::SimulationsData.k3d[0])+" ("+System::Convert::ToString(cDataContainer::SimulationsData.n3d[0])+") m^-1\n";
	text += "# ky(ny):\t" + System::Convert::ToString(cDataContainer::SimulationsData.k3d[1])+" ("+System::Convert::ToString(cDataContainer::SimulationsData.n3d[1])+") m^-1\n";
	text += "# kz(nz):\t" + System::Convert::ToString(cDataContainer::SimulationsData.k3d[2])+" ("+System::Convert::ToString(cDataContainer::SimulationsData.n3d[2])+") m^-1\n";

	Delete3DMode();

}

void mcSample::SaveProfilesBatch()
{
	switch(mcSettings::m_mmdBSMode)
	{
	case 0:
		// save images
		break;
	case 1:
		// save 3D ASCII profiles of the modes

		System::Windows::Forms::OpenFileDialog^ OpenSBTFile = gcnew System::Windows::Forms::OpenFileDialog();
		OpenSBTFile->Title = L"Open file with the list of profiles to save";
		OpenSBTFile->Multiselect = false;
		OpenSBTFile->Filter = "batch file of 3D ASCII profiles (*.sbt) |*.sbt| All files (*.*)|*.*";
		OpenSBTFile->DefaultExt = "sbt";

		if (OpenSBTFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			System::IO::StreamReader^ binReader = gcnew System::IO::StreamReader(System::IO::File::Open( OpenSBTFile->FileName, System::IO::FileMode::Open ) );
			System::String^ header = binReader->ReadLine();
			header->ToUpper();
			if (header != "# SBT") return;
			header = binReader->ReadLine();
			header->ToUpper();
			int bmode = 0;
			if (header = "# FLOAT") bmode = 0;
			else if (header = "# INT") bmode = 1;
			else return;
			// From now the stream points to the 1D array of frequencies
			// Pick the folder
			System::Windows::Forms::FolderBrowserDialog^ BrowseDynamicsFolder = gcnew System::Windows::Forms::FolderBrowserDialog();
			BrowseDynamicsFolder->ShowNewFolderButton = false;
			BrowseDynamicsFolder->Description = L"Please pick the folder where to save the profiles";
			if (BrowseDynamicsFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if (System::IO::Directory::Exists(BrowseDynamicsFolder->SelectedPath))
				{
					System::String^ path = System::String::Copy(BrowseDynamicsFolder->SelectedPath);
					while (binReader->Peek() != -1)
					{
						System::String^ modens = binReader->ReadLine();
						//Read the data
						long long moden = 0;
						double modenf = 0.0;
						switch(bmode)
						{
						case 0:
							modenf = System::Convert::ToDouble(modens);
							moden = (long long)modenf / cDataContainer::SimulationsData.s_params.m_ResFrequency;
							break;
						case 1:
							moden = System::Convert::ToInt64(modens);
							modenf = (double)moden * cDataContainer::SimulationsData.s_params.m_ResFrequency;
							break;
						}
						mcSettings::m_mmdStepf = (float)modenf;
						mcSettings::m_mmdStepi = moden;

						System::String^ wavenum = gcnew System::String("");
						mcSample::GetModeWaveVectors(wavenum);

						mcSample::Get3DMode();
						long long mode = 0;
						System::String^ name = gcnew System::String("");
						System::String^ header = gcnew System::String("# SEMARGL3 OUTPUT:\n");
						header += L"# 3D profile of magnetization of the given time/frequency and depth/wavevector\n";
						header += wavenum;
						GenerateTextForProfiles3D(name, header, mode);
						header += "# X Y Z VALUE VALUE\n";
						
						System::String^ fname = path + FOLDERDELIM + name + ".dat";
						mcSample::Save3DToTextFile(fname,
												header,
												mode);

						mcSample::Delete3DMode();
					}
				}
			}

			binReader->Close();	
		}
		break;
	}
}

void mcSample::GenerateTextForProfiles3D(System::String^% name, System::String^% header, long long graph)
{
			 
	System::String^ component= gcnew System::String("M");
	switch(cDataContainer::p_ExtractingMethod.m_MagnetizationComponent)
	{
	case 0:
		component += L"x)";
		break;
	case 1:
		component += L"y)";
		break;
	case 2:
		component += L"z)";
		break;
	}
	header += L"# COMPONENT:\t";
	switch(graph)
	{
	case 0:
		switch(mcSettings::m_mmdMode)
		{
		case 0:
			name += L"Re(";
			name += component;
			name += "-";

			header += "Re(";
			header += component;
			header += "\n";
			break;
		case 1:
			name += L"Amp(";
			name += component;
			name += "-";

			header += L"Amp(";
			header += component;
			header += "\n";
			break;
		}
		break;
	case 1:
		switch(mcSettings::m_mmdMode)
		{
		case 0:
			name += L"Img(";
			name += component;
			name += "-";

			header += L"Img(";
			header += component;
			header += "\n";
			break;
		case 1:
			name += L"Phs(";
			name += component;
			name += "-";

			header += L"Phs(";
			header += component;
			header += "\n";
			break;
		}
		break;
	case 2:
		switch(mcSettings::m_mmdMode)
		{
		case 0:
			name += L"Re(";
			name += component;
			name += "-";

			header += "Re(";
			header += component;
			header += " ";

			name += L"Img(";
			name += component;
			name += "-";
					 
			header += L"Img(";
			header += component;
			header += "\n";
			break;
		case 1:
			name += L"Amp(";
			name += component;
			name += "-";

			header += "Phase(";
			header += component;
			header += " ";

			name += L"Amp(";
			name += component;
			name += "-";
					 
			header += L"Phase(";
			header += component;
			header += "\n";
			break;
		}
		break;

	}
	float time = 0.0F;
	System::String^ stime;
	float depth = 0.0F;
	System::String^ sdepth;

	switch(cDataContainer::SimulationsData.m_IsFreqDomain)
	{
	case 0:
		time = mcSettings::m_mmdStepf;
		stime = System::Convert::ToString(time);
		name += "T";
		name += stime;
		name += "s-";
		header += L"# TIME:\t";
		header += stime;
		header += " s\n";
		break;
	case 1:
		float freq = mcSettings::m_mmdStepf * 1e-9; // Hz to GHZ
		System::String^ sfreq = System::Convert::ToString(freq);
		name += "F";
		name += sfreq;
		name += "GHz-";
		header += L"# FREQUENCY:\t";
		header += sfreq;
		header += " GHz\n";
		break;
	}
}

void mcSample::Clean()
{
	sample_xy->~Bitmap();
	sample_xz->~Bitmap();
	sample_yz->~Bitmap();

	trs_image->~Bitmap();
	frs_image->~Bitmap();

	mag_re->~Bitmap();
	mag_img->~Bitmap();
	spectrum->~Bitmap();
	dispersion->~Bitmap();
}