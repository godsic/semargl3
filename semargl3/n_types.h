#ifndef _N_TYPES_H
#define _N_TYPES_H

#pragma unmanaged
typedef enum save_regime{
	A1D = 0,
	A2D = 1,
	A3D = 2,
	A4D = 3
};

typedef enum save_datatype{
	REAL = 0,
	CMPX = 1,
	CMPX_RE = 2,
	CMPX_IMG =3,
	CMPX_AP = 4,
	CMPX_A = 5,
	CMPX_P = 6
};
typedef unsigned long long uint;		// Definition of the useful uint type
#define MAX_FILENAME_LEN 512    // Defines the maximum lenght of the filenames
#define BUFF_LEN	256			// Defines the char buffer for file I/O
#define MAX_MS		256			// Defines the maximum number of the value of the magnatization of saturation across the sample
#define MS_RERROR   1e-5		// Defines the rounding error threshould when comparing different magnetization of saturation values
#define MAX_CC_VAL  255			// Defines the maximum value of the color component of the images
#define MAX_CC_VAL_HALF 128		// Defines the half of the maximum value of the color component of the images
#define FILLCOLOUR 255
#define FOLDERDELIM "\\"
#define PEAKREJ		1e-2

// Defines complex number structure
struct COMPLEX
{
public: float Re;		// Real part of the complex number
public: float Img;		// Imaginary part of the complex number
};
//Defines structure containing parameters of simulations
struct SIMPARAMS
{
public: long long m_SizeX;	// Number of cells in X direction
public: long long m_SizeY;	// Number of cells in Y direction
public: long long m_SizeZ;	// Number of cells in Z direction

public: double m_CellSizeX;	// Unit cell size along X direction
public: double m_CellSizeY;	// Unit cell size along Y direction
public: double m_CellSizeZ;	// Unit cell size along Z direction

public: long long m_NumberOfTimeSteps;			// The total number of detected time steps (by probing folder conatining *.omf files)
public: double m_StageTime;					// Stage time of the simulations (time step)
public: double m_SimulationsTotalTime;		// Total time of the simulations

public: double m_MaxFrequency;				// Frequency bandwidth of the simulations Fm = 1/(2*dt)
public: double m_MaxInverseWavelengthX;		// Inverse wavelength bandwidth of the sample Kmx = 1/(2*dx)
public: double m_MaxInverseWavelengthY;		// Inverse wavelength bandwidth of the sample Kmy = 1/(2*dy)
public: double m_MaxInverseWavelengthZ;		// Inverse wavelength bandwidth of the sample Kmz = 1/(2*dz)

public: double m_ResFrequency;				// Frequency resolution of the simulations Fm = 1/(2*dt)/m_NumberOfTimeSteps
public: double m_ResInverseWavelengthX;		// Inverse wavelength resolution of the sample Kmx = 1/(2*dx)/m_SizeX
public: double m_ResInverseWavelengthY;		// Inverse wavelength resolution of the sample Kmy = 1/(2*dy)/m_SizeY
public: double m_ResInverseWavelengthZ;		// Inverse wavelength resolution of the sample Kmz = 1/(2*dz)/m_SizeZ

public: double m_pMs[MAX_MS];				// Magnetization of the saturation of the sample (may containe several values)
public: long long m_MsCount;						// The total number of different values of Ms in m_pMs;
public: double m_MsMax;						// The maximum value of the magnetization of saturation
public: char m_pMIFFileName[MAX_FILENAME_LEN];				// Contains the name of the MIF file describing this particular simulation	
public: char m_pStaticFileName[MAX_FILENAME_LEN];			// The name of the file describing ground state of the sample
public: char m_pFolderWithTheData[MAX_FILENAME_LEN];			// Contains path to the folder containing dynamic data
};
#pragma managed
#endif