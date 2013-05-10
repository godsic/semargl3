
#include "m_image.h"
#include "n_data.h"
#include "m_sample.h"
#include "n_image.h"
#include "n_mag_class.h"
#include "n_probe.h"
#include "m_settings.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

mcImage::mcImage(void)
{
}

void mcImage::GenerateSampleProfileImage()
{
	long long sizeX = cDataContainer::SimulationsData.s_params.m_SizeX;
	long long sizeY = cDataContainer::SimulationsData.s_params.m_SizeY;
	long long sizeZ = cDataContainer::SimulationsData.s_params.m_SizeZ;
	
	mcSample::sample_xy = gcnew Bitmap(sizeX, sizeY, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	mcSample::sample_xz = gcnew Bitmap(sizeX, sizeZ, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	mcSample::sample_yz = gcnew Bitmap(sizeY, sizeZ, System::Drawing::Imaging::PixelFormat::Format24bppRgb);

	//plot xy

	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,mcSample::sample_xy->Width,mcSample::sample_xy->Height);	
	System::Drawing::Imaging::BitmapData^ bmpData = mcSample::sample_xy->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mcSample::sample_xy->PixelFormat );
	IntPtr ptr = bmpData->Scan0;
	long long bytes = bmpData->Stride * mcSample::sample_xy->Height;
	cImage::DrawSampleXY(sizeX, sizeY, sizeZ, (float*)cDataContainer::SimulationsData.static_data, (unsigned char*)ptr.ToPointer(), bmpData->Stride);
	mcSample::sample_xy->UnlockBits(bmpData);

	//plot xz

	rect = System::Drawing::Rectangle(0,0,mcSample::sample_xz->Width,mcSample::sample_xz->Height);	
	bmpData = mcSample::sample_xz->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mcSample::sample_xz->PixelFormat );
	ptr = bmpData->Scan0;
	bytes = bmpData->Stride * mcSample::sample_xz->Height;
	cImage::DrawSampleXZ(sizeX, sizeY, sizeZ, (float*)cDataContainer::SimulationsData.static_data, (unsigned char*)ptr.ToPointer(), bmpData->Stride);
	mcSample::sample_xz->UnlockBits(bmpData);

	//plot yz

	rect = System::Drawing::Rectangle(0,0,mcSample::sample_yz->Width,mcSample::sample_yz->Height);	
	bmpData = mcSample::sample_yz->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mcSample::sample_yz->PixelFormat );
	ptr = bmpData->Scan0;
	bytes = bmpData->Stride * mcSample::sample_yz->Height;
	cImage::DrawSampleYZ(sizeX, sizeY, sizeZ, (float*)cDataContainer::SimulationsData.static_data, (unsigned char*)ptr.ToPointer(), bmpData->Stride);
	mcSample::sample_yz->UnlockBits(bmpData);

}

void mcImage::DrawRectProbeXY()
{
	GenerateSampleProfileImage();
	// Add the rectangular probe
	System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(mcSample::sample_xy);
	//g->DrawImage(mcSample::sample_xy,System::Drawing::Point(0,0));
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(Color::FromArgb(128,128,0,0),3.0);
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(Color::FromArgb(128,200,0,0));
	//g->DrawRectangle(pen,cProbe::X0, cProbe::Y0, cProbe::sizeX, cProbe::sizeY);
	g->FillRectangle(brush,(int)cProbe::X0, (int)cProbe::Y0, (int)cProbe::sizeX, (int)cProbe::sizeY);
	delete g;
}

void mcImage::DrawRectProbeXZ()
{
	GenerateSampleProfileImage();
	// Add the rectangular probe
	System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(mcSample::sample_xz);
	//g->DrawImage(mcSample::sample_xz,System::Drawing::Point(0,0));
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(Color::FromArgb(128,128,0,0),3.0);
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(Color::FromArgb(128,200,0,0));
	//g->DrawRectangle(pen,cProbe::X0, cProbe::Y0, cProbe::sizeX, cProbe::sizeY);
	g->FillRectangle(brush,(int)cProbe::X0, (int)cProbe::Z0, (int)cProbe::sizeX, (int)cProbe::sizeZ);
	delete g;
}

void mcImage::DrawRectProbeYZ()
{
	GenerateSampleProfileImage();
	// Add the rectangular probe
	System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(mcSample::sample_yz);
	//g->DrawImage(mcSample::sample_yz,System::Drawing::Point(0,0));
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(Color::FromArgb(128,128,0,0),3.0);
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(Color::FromArgb(128,200,0,0));
	//g->DrawRectangle(pen,cProbe::X0, cProbe::Y0, cProbe::sizeX, cProbe::sizeY);
	g->FillRectangle(brush,(int)cProbe::Y0, (int)cProbe::Z0, (int)cProbe::sizeY, (int)cProbe::sizeZ);
	delete g;
}

void mcImage::DrawProbe()
{
	switch(cProbe::ProbeType)
	{
	case 0:
		//NO PROBE
		break;
	case 1:
		switch(mcSettings::m_prViewPortProj)
		{
		case 0:
			DrawRectProbeXY();
			break;
		case 1:
			DrawRectProbeXZ();
			break;
		case 2:
			DrawRectProbeYZ();
			break;
		}
		break;
	case 2:
		// NOT YET IMPLEMENTED
		break;
	}
}
void mcImage::Draw2DTRS()
{
	long long sizeX = cDataContainer::SimulationsData.m_asizeX;
	long long sizeY = cDataContainer::SimulationsData.m_asizeY;
	long long sizeZ = cDataContainer::SimulationsData.m_asizeT;
	mcSample::trs_image = gcnew Bitmap(sizeX, sizeZ, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	//plot 2d

	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,mcSample::trs_image->Width,mcSample::trs_image->Height);	
	System::Drawing::Imaging::BitmapData^ bmpData = mcSample::trs_image->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mcSample::trs_image->PixelFormat );
	IntPtr ptr = bmpData->Scan0;
	long long bytes = bmpData->Stride * mcSample::trs_image->Height;
	unsigned char zero[3] = {0,0,0};
	//cImage::DrawAmp2DCMPXData(sizeX,sizeZ,cDataContainer::SimulationsData.avgdata,(unsigned char*)ptr.ToPointer(),bmpData->Stride, mcSettings::m_trTRSImageBr, zero, (long long)0);
	cImage::Draw2DRealDataRB(sizeX,sizeZ,cDataContainer::SimulationsData.avgdata,(unsigned char*)ptr.ToPointer(),bmpData->Stride, mcSettings::m_trTRSImageBr);
	mcSample::trs_image->UnlockBits(bmpData);
	mcSample::trs_image->RotateFlip(System::Drawing::RotateFlipType::Rotate180FlipX);
}

void mcImage::Draw2DFRS()
{
	long long sizeX = cDataContainer::SimulationsData.m_asizeX;
	long long sizeY = cDataContainer::SimulationsData.m_asizeY;
	long long sizeZ = cDataContainer::SimulationsData.m_asizeT / 2; // due to FFT
	mcSample::frs_image = gcnew Bitmap(sizeX, sizeZ, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	//plot 2d
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,mcSample::frs_image->Width,mcSample::frs_image->Height);	
	System::Drawing::Imaging::BitmapData^ bmpData = mcSample::frs_image->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mcSample::frs_image->PixelFormat );
	IntPtr ptr = bmpData->Scan0;
	long long bytes = bmpData->Stride * mcSample::frs_image->Height;
	unsigned char zero[3] = {0,0,0};
	long long brightness = mcSettings::m_trFRSImageBr;
	long long colourspace = mcSettings::m_trFRSMode;
	cImage::DrawAmp2DCMPXData(sizeX, sizeZ, cDataContainer::SimulationsData.avgdata_fft, (unsigned char*)ptr.ToPointer(), bmpData->Stride, brightness, zero, colourspace,(long long)1);
	mcSample::frs_image->UnlockBits(bmpData);
	mcSample::frs_image->RotateFlip(System::Drawing::RotateFlipType::Rotate180FlipX);

}

void mcImage::Draw2DMagRe()
{
	long long sizeX = cDataContainer::SimulationsData.m_lsizeX;
	long long sizeY = cDataContainer::SimulationsData.m_lsizeY;
	mcSample::mag_re = gcnew Bitmap(sizeX, sizeY, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	//plot 2d
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,mcSample::mag_re->Width,mcSample::mag_re->Height);	
	System::Drawing::Imaging::BitmapData^ bmpData = mcSample::mag_re->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mcSample::mag_re->PixelFormat );
	IntPtr ptr = bmpData->Scan0;
	long long bytes = bmpData->Stride * mcSample::mag_re->Height;
	unsigned char zero[3] = {FILLCOLOUR,FILLCOLOUR,FILLCOLOUR};
	switch(mcSettings::m_mmdMode)
	{
	case 0:
		// Re plus Img
		if (cDataContainer::SimulationsData.m_IsFreqDomain || cDataContainer::SimulationsData.m_IsFreqDomain) 
		{
			cImage::DrawRe2DCMPXData(sizeX, sizeY, 
				cDataContainer::SimulationsData.layer_buff_2d, (unsigned char*)ptr.ToPointer(), bmpData->Stride,1.0F);
		}
		else
		{
			cImage::Draw2DRealDataRB(sizeX, sizeY, 
				cDataContainer::SimulationsData.layer_buff_2d, (unsigned char*)ptr.ToPointer(), bmpData->Stride, 1.0F);
		}
		break;
	case 1:
		if (cDataContainer::SimulationsData.m_IsFreqDomain || cDataContainer::SimulationsData.m_IsFreqDomain) 
		{
			cImage::DrawAmp2DCMPXData(sizeX, sizeY, 
				cDataContainer::SimulationsData.layer_buff_2d, (unsigned char*)ptr.ToPointer(), bmpData->Stride, 1.0F, zero, (long long)0,(long long)0);
		}
		else
		{
			cImage::Draw2DRealDataRB(sizeX, sizeY, 
				cDataContainer::SimulationsData.layer_buff_2d, (unsigned char*)ptr.ToPointer(), bmpData->Stride, 1.0F);
		}
		break;
	}
	mcSample::mag_re->UnlockBits(bmpData);
	mcSample::mag_re->RotateFlip(System::Drawing::RotateFlipType::Rotate180FlipX);
}

void mcImage::Draw2DMagImg()
{
	long long sizeX = cDataContainer::SimulationsData.m_lsizeX;
	long long sizeY = cDataContainer::SimulationsData.m_lsizeY;
	mcSample::mag_img = gcnew Bitmap(sizeX, sizeY, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	//plot 2d
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,mcSample::mag_img->Width,mcSample::mag_img->Height);	
	System::Drawing::Imaging::BitmapData^ bmpData = mcSample::mag_img->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mcSample::mag_img->PixelFormat );
	IntPtr ptr = bmpData->Scan0;
	long long bytes = bmpData->Stride * mcSample::mag_img->Height;
	switch(mcSettings::m_mmdMode)
	{
	case 0:
		// Re plus Img
		if (cDataContainer::SimulationsData.m_IsFreqDomain || cDataContainer::SimulationsData.m_IsFreqDomain) 
		{
			cImage::DrawImg2DCMPXData(sizeX, sizeY, 
				cDataContainer::SimulationsData.layer_buff_2d, (unsigned char*)ptr.ToPointer(), bmpData->Stride, 1.0F);
		}
		else
		{
			cImage::Draw2DRealDataRB(sizeX, sizeY, 
				cDataContainer::SimulationsData.layer_buff_2d, (unsigned char*)ptr.ToPointer(), bmpData->Stride, 1.0F);
		}
		break;
	case 1:
		if (cDataContainer::SimulationsData.m_IsFreqDomain || cDataContainer::SimulationsData.m_IsFreqDomain) 
		{
			cImage::DrawPhase2DCMPXData(sizeX, sizeY, 
				cDataContainer::SimulationsData.layer_buff_2d, (unsigned char*)ptr.ToPointer(), bmpData->Stride, 1.0F);
		}
		else
		{
			cImage::Draw2DRealDataRB(sizeX, sizeY, 
				cDataContainer::SimulationsData.layer_buff_2d, (unsigned char*)ptr.ToPointer(), bmpData->Stride, 1.0F);
		}
		break;
	}
	mcSample::mag_img->UnlockBits(bmpData);
	mcSample::mag_img->RotateFlip(System::Drawing::RotateFlipType::Rotate180FlipX);
}

void mcImage::Draw2DDispersionSlice()
{
	long long sizeX = cDataContainer::SimulationsData.m_asizeX;
	long long sizeY = cDataContainer::SimulationsData.m_asizeY;
	long long sizeZ = cDataContainer::SimulationsData.m_asizeZ;
	long long sizeT = cDataContainer::SimulationsData.m_asizeT;

	unsigned char zero[3] = {0,0,0};

	mcSample::dispersion = gcnew Bitmap(sizeX, sizeT, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
	//plot 2d
	long long colorscale = mcSettings::m_dcColorScale;
	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,mcSample::dispersion->Width,mcSample::dispersion->Height);	
	System::Drawing::Imaging::BitmapData^ bmpData = mcSample::dispersion->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mcSample::dispersion->PixelFormat );
	IntPtr ptr = bmpData->Scan0;
	long long bytes = bmpData->Stride * mcSample::dispersion->Height;
	if (mcSettings::m_dcAvgMethodX == 1 || mcSettings::m_dcAvgMethodY == 1 || mcSettings::m_dcAvgMethodZ == 1) cImage::DrawPostitive2DRealData(sizeX,sizeT,cDataContainer::SimulationsData.avgdata_fft,(unsigned char*)ptr.ToPointer(),bmpData->Stride, mcSettings::m_dcImageBr, colorscale); // data are in the Amp; Phase form
	else cImage::DrawAmp2DCMPXData(sizeX,sizeT,cDataContainer::SimulationsData.avgdata_fft,(unsigned char*)ptr.ToPointer(),bmpData->Stride, mcSettings::m_dcImageBr, zero, colorscale, (long long)0); // data are in the Re; Img form
	mcSample::dispersion->UnlockBits(bmpData);
	mcSample::dispersion->RotateFlip(System::Drawing::RotateFlipType::Rotate180FlipX);

}

void mcImage::SaveImage(System::Drawing::Bitmap ^img)
{

}
