#include "m_settings.h"
#include "n_data.h"

mcSettings::mcSettings(void)
{
}

long long mcSettings::m_etPointsX = 0;
long long mcSettings::m_etPointsY = 0;
long long mcSettings::m_etPointsZ = 0;
long long mcSettings::m_etPointsT = 0;

long long mcSettings::m_eiFormat = 0;

long long mcSettings::m_aoFFTWindowType = 0;
double mcSettings::m_aoKeiserCoeff = 1.0;

long long mcSettings::m_prViewPortProj = 0;

long long mcSettings::m_etExportFormat = 0;

long long mcSettings::m_trAveragingPlane = 0;

long long mcSettings::m_mmdProjType = 0;
long long mcSettings::m_mmdMode = 0;
long long mcSettings::m_mmdBSMode = 1;
long long mcSettings::m_mmdStepi = 0;
float mcSettings::m_mmdStepf = 0.0F;
long long mcSettings::m_mmdDepthi = 0;
float mcSettings::m_mmdDepthf = 0.0F;

long long mcSettings::m_fdaMethod = 0;
long long mcSettings::m_fdaMode = 0;
long long mcSettings::m_fdaAvgMethod = 0;

long long mcSettings::m_dcAvgMethodX = 0;
long long mcSettings::m_dcAvgMethodY = 0;
long long mcSettings::m_dcAvgMethodZ = 0;

long long mcSettings::m_dcIsAvgX = 0;
long long mcSettings::m_dcIsAvgY = 0;
long long mcSettings::m_dcIsAvgZ = 0;

long long mcSettings::m_dcProbeXi = 0;
float mcSettings::m_dcProbeXf = 0.0F;
long long mcSettings::m_dcProbeYi = 0;
float mcSettings::m_dcProbeYf = 0.0F;
long long mcSettings::m_dcProbeZi = 0;
float mcSettings::m_dcProbeZf = 0.0F;

long long mcSettings::m_dcMode = 0;
long long mcSettings::m_dcImageBr = 1;

long long mcSettings::m_trTRSImageBr = 1;
long long mcSettings::m_trFRSImageBr = 1;
long long mcSettings::m_trFRSMode = 0;

long long mcSettings::m_dcColorScale = 0;
long long mcSettings::m_clMode = 0; // default is spectral
long long mcSettings::m_pbType = 0;
long long mcSettings::m_pbX0 = -1;
long long mcSettings::m_pbY0 = -1;
long long mcSettings::m_pbZ0 = -1;
long long mcSettings::m_pbX1 = -1;
long long mcSettings::m_pbY1 = -1;
long long mcSettings::m_pbZ1 = -1;
long long mcSettings::m_dpMagnetization = 0;
char* mcSettings::m_dpStaticFileName;
char* mcSettings::m_dpDataFolder;
char* mcSettings::m_dpOut;
char** mcSettings::m_dpDataFileNames;
long long mcSettings::m_dpFilesCount = 0;
long long mcSettings::m_dpPreProcMethod = 0;

void mcSettings::ProcessCommands(array<System::String^>^ params)
{
	//
	long long rank = params->GetLongLength(0);
	System::String^ path="";
	System::String^ fstatic=""; 
	for (long long i = 0 ; i < rank; i++)
	{
		System::String^ aline = params[i];

		// Type of the analysis
		if (params[i] == "--mode")
		{
			i++;
			if (params[i] == "spectral")
			{
				m_clMode = 0;
				System::Console::WriteLine("Mode:\tSpectral analysis");
				continue;
			}
			if (params[i] == "dispersion")
			{
				m_clMode = 1;
				System::Console::WriteLine("Mode:\tCalculation of dispersion");
				continue;
			}
			i--;
		}
		// Method of the analysis
		if (params[i] == "--method")
		{
			i++;
			if (params[i] == "f2a")
			{
				System::Console::WriteLine("Spectral method:\tf2a");
				m_fdaMethod = 0;
				m_fdaAvgMethod = 1;
				m_fdaMode = 1;
				continue;
			}
			if (params[i] == "a2f")
			{
				System::Console::WriteLine("Spectral method:\ta2f");
				m_fdaMethod = 1;
				m_fdaAvgMethod = 0;
				m_fdaMode = 1;
				continue;
			}

			if (params[i] == "a2fc")
			{
				System::Console::WriteLine("Spectral method:\tafc");
				m_fdaMethod = 1;
				m_fdaAvgMethod = 0;
				m_fdaMode = 0;
				continue;
			}

			if (params[i] == "d2a")
			{
				System::Console::WriteLine("Spectral method:\td2a");
				m_fdaMethod = 2;
				m_fdaAvgMethod = 1;
				m_fdaMode = 1;
				continue;
			}
			i--;
		}
		// probe
		if (params[i] == "--probe")
		{
			i++;
			if (params[i] == "whole")
			{
				m_pbType = 0;
				System::Console::WriteLine("Probe:\tEntire sample");
				continue;
			}
			if (params[i] == "rect")
			{
				m_pbType = 1;
				System::Console::WriteLine("Probe:\tRectangular");
				continue;
			}
			if (params[i] == "file")
			{
				m_pbType = 2;
				System::Console::WriteLine("Probe:\tDefined by file");
				continue;
			}		
			i--;
		}

		if (params[i] == "--region")
		{
			i++;
			if (params[i] = "-") m_pbX0 = -1;
			else m_pbX0 = System::Convert::ToInt64(params[i]);
			i++;
			if (params[i] = "-") m_pbY0 = -1;
			else m_pbY0 = System::Convert::ToInt64(params[i]);
			i++;
			if (params[i] = "-") m_pbZ0 = -1;
			else m_pbZ0 = System::Convert::ToInt64(params[i]);
			i++;
			if (params[i] = "-") m_pbX1 = -1;
			else m_pbX1 = System::Convert::ToInt64(params[i]);
			i++;
			if (params[i] = "-") m_pbY1 = -1;
			else m_pbY1 = System::Convert::ToInt64(params[i]);
			i++;
			if (params[i] = "-") m_pbZ1 = -1;
			else m_pbZ1 = System::Convert::ToInt64(params[i]);
			continue;
		}

		if (params[i] == "--m")
		{
			i++;
			if (params[i] == "x")
			{
				m_dpMagnetization = 0;
				System::Console::WriteLine("Component of mangetization to be analysed:\tMx");
				continue;
			}
			if (params[i] == "y")
			{
				m_dpMagnetization = 1;
				System::Console::WriteLine("Component of mangetization to be analysed:\tMy");
				continue;
			}
			if (params[i] == "z")
			{
				m_dpMagnetization = 2;
				System::Console::WriteLine("Component of mangetization to be analysed:\tMz");
				continue;
			}
			i--;
		}
		if (params[i] == "--static")
		{
			i++;
			m_dpPreProcMethod = 1;
			fstatic = params[i];
			System::Console::WriteLine("Path to the static file: \t{0}",params[i]);
			pin_ptr<const wchar_t> wch = PtrToStringChars(params[i]);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((params[i]->Length + 1) * 2);
			errno_t err = 0;
			m_dpStaticFileName = (char *)malloc(sizeInBytes);

			err = wcstombs_s(&convertedChars, 
							m_dpStaticFileName, sizeInBytes,
							wch, sizeInBytes);	
			continue;
		}
		if (params[i] == "--dfolder")
		{
			i++;
			path = params[i];
			System::Console::WriteLine("Path to the data: \t{0}",params[i]);
			pin_ptr<const wchar_t> wch = PtrToStringChars(params[i]);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((params[i]->Length + 1) * 2);
			errno_t err = 0;
			m_dpDataFolder = (char *)malloc(sizeInBytes);

			err = wcstombs_s(&convertedChars, 
							m_dpDataFolder, sizeInBytes,
							wch, sizeInBytes);
			continue;
		}

		if (params[i] == "--windowing")
		{
			i++;
			if (params[i] == "none")
			{
				m_aoFFTWindowType = 0;
				System::Console::WriteLine("DFT windowing function:\tnone");
				continue;
			}
			if (params[i] == "welch")
			{
				m_aoFFTWindowType = 1;
				System::Console::WriteLine("DFT windowing function:\tWelch");
				continue;
			}
			if (params[i] == "kaiser")
			{
				m_aoFFTWindowType = 2;
				System::Console::WriteLine("DFT windowing function:\tKaiser");
				i++;
				m_aoKeiserCoeff = System::Convert::ToDouble(params[i]);
				continue;
			}
			i--;
		}
		if (params[i] == "--out")
		{
			i++;
			System::Console::WriteLine("Output filename: \t{0}",params[i]);
			pin_ptr<const wchar_t> wch = PtrToStringChars(params[i]);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((params[i]->Length + 1) * 2);
			errno_t err = 0;
			m_dpOut = (char *)malloc(sizeInBytes);

			err = wcstombs_s(&convertedChars, 
							m_dpOut, sizeInBytes,
							wch, sizeInBytes);
			continue;
		}
	}
	if (path->Length == 0)
	{	
		path = System::IO::Path::GetDirectoryName(fstatic);
		System::Console::WriteLine("Path to the data: \t{0}",path);
		pin_ptr<const wchar_t> wch = PtrToStringChars(path);
		size_t convertedChars = 0;
		size_t  sizeInBytes = ((path->Length + 1) * 2);
		errno_t err = 0;
		m_dpDataFolder = (char *)malloc(sizeInBytes);

		err = wcstombs_s(&convertedChars, 
						m_dpDataFolder, sizeInBytes,
						wch, sizeInBytes);
	}
	array<System::String^>^ str = System::IO::Directory::GetFiles(path, "*.omf");
	System::Array::Sort(str); // to ensure that correct order of files is preserved
	long long FileCount = str->GetLength(0);
	m_dpFilesCount = FileCount;
	System::Console::WriteLine("semargl3 has found:\t {0} files in the specified folder",FileCount);
	m_dpDataFileNames = (char**) new char*[FileCount];
	for (long long i = 0; i < FileCount; i++)
	{
		pin_ptr<const wchar_t> wch = PtrToStringChars(str[i]);
		size_t convertedChars = 0;
		size_t sizeInBytes = ((str[i]->Length + 1) * 2);
		errno_t err = 0;
		m_dpDataFileNames[i] = (char*) new char[sizeInBytes];		//(char*)calloc(sizeInBytes,sizeof(char));
		//cDataContainer::m_pDynamicFileNames[i] = (char*)new char[sizeInBytes];
		err = wcstombs_s(&convertedChars, 
			m_dpDataFileNames[i], sizeInBytes,
						wch, sizeInBytes);
		if (err !=0)
		{
			System::Console::WriteLine("Error while marshaling data from Managed to Native code");
		}
	}

	return;
}