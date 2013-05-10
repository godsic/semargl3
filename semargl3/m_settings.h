
#pragma once

#include <vcclr.h>

#if _MSC_VER > 1499 // Visual C++ 2008 only
#include <msclr/marshal.h>
using namespace msclr::interop;
#endif 

public class mcSettings
{
public:
	mcSettings(void);
	
	static long long m_clMode;

	static long long m_etPointsX;// defines the maximum number of points to be exported to the text formats
	static long long m_etPointsY;
	static long long m_etPointsZ;
	static long long m_etPointsT;/////////////////////////////////////////////////////////////////////////

	static long long m_etExportFormat;// defines whenever export the data in amplitude_phase (0) or complex (1) regime
	// Output image format
	static long long m_eiFormat; // 0 - TIFF, 1 - PNG, 2 - BMP
	// Analysies options

	static long long m_aoFFTWindowType; // 0 - None, 1 - Welch, 2 - Keiser
	static double m_aoKeiserCoeff; // default value: 1.0

	static long long m_prViewPortProj; // 0-xy, 1-xz, 2 - yz

	static long long m_trAveragingPlane;// 0- yz, 1 - xz, 2 - xy

	static long long m_trTRSImageBr;
	static long long m_trFRSImageBr;
	static long long m_trFRSMode;

	// mmDisplay
	static long long m_mmdProjType; // 0 - xy, 1 - xz, 2 -yz;
	static long long m_mmdStepi;
	static float m_mmdStepf;
	static long long m_mmdMode;   // 0 - Real and Imaginary, 1 - Amplitude and phase
	static long long m_mmdBSMode; // 0 - images, 1 - text
	static long long m_mmdDepthi;
	static float m_mmdDepthf;

	// Frequency domain analysies
	static long long m_fdaMethod; // 0 - F2A, 1 - A2F
	static long long m_fdaMode;   // 0 - ReImg, 1 - AmpPhase
	static long long m_fdaAvgMethod; // 0 - COMPLEX, 1 - COMPLEX AMP 

	// data preprocessing
	static long long m_dpMagnetization;
	static char* m_dpStaticFileName;
	static char* m_dpDataFolder;
	static char* m_dpOut;
	static char** m_dpDataFileNames;
	static long long m_dpFilesCount;
	static long long m_dpPreProcMethod;
	// probe

	static long long m_pbType; // 0 - no, 1 - rect, 2 - file
	static long long m_pbX0;
	static long long m_pbY0;
	static long long m_pbZ0;
	static long long m_pbX1;
	static long long m_pbY1;
	static long long m_pbZ1;

	// dispersion calculation
	static long long m_dcAvgMethodX;
	static long long m_dcAvgMethodY;
	static long long m_dcAvgMethodZ;
	static long long m_dcIsAvgX;
	static long long m_dcIsAvgY;
	static long long m_dcIsAvgZ;

	static long long m_dcColorScale; // 0 - linear, 1 - log10, 2 - sqrt

	static long long m_dcProbeXi;
	static float m_dcProbeXf;

	static long long m_dcProbeYi;
	static float m_dcProbeYf;

	static long long m_dcProbeZi;
	static float m_dcProbeZf;
	
	static long long m_dcMode;
	static long long m_dcImageBr;

	static void ProcessCommands(array<System::String^>^ params);
};

