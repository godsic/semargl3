#include "n_data.h"
#pragma unmanaged

EXMETHOD cDataContainer::p_ExtractingMethod;
char* cDataContainer::m_pDynamicFilesFolder;
char* cDataContainer::m_pGroundStateFileName;
char **cDataContainer::m_pDynamicFileNames;
long long cDataContainer::m_nNumberOfDynamicFiles = 0;
cMagnetization cDataContainer::SimulationsData;

void cDataContainer::Clean()
{
	SimulationsData.CleanBuffers();
}

#pragma managed