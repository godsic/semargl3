#ifndef _N_DATA_H
#define _N_DATA_H



//Defines the conatiner of the all relevant software data
//MAD
//2010
#pragma unmanaged

#include "n_premethod_stuct.h"
#include "n_mag_class.h"

//This class represent the container of the data used by the software
class cDataContainer
{
	public: static EXMETHOD p_ExtractingMethod;	// Describes the method of the data processing pre- and during loading
	public:	static cMagnetization SimulationsData;	// Contains the data extracted from the simulations together with the processining methods
	public: static char* m_pGroundStateFileName;	// Contains the path to the file with the ground state magnetization
	public: static char* m_pDynamicFilesFolder;		// Contains the path to the folder containing the full set of the dynamic files
	public: static char **m_pDynamicFileNames;		// Contains the filenames of the files located in the m_pDynamicFilesFolder folder
	public: static long long	m_nNumberOfDynamicFiles;	// The number of the dynamic files located in m_pDynamicFilesFolder
	public: static void Clean();
};


#pragma managed


#endif