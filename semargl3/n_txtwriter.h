#ifndef _N_TXTWRITER_H
#define _N_TXTWRITER_H

#pragma unmanaged
#include "n_types.h"
class cTXTWriter
{
public: static long long SaveToFile(float* data, long long sizex, long long sizey, long long sizez, long long sizet, 
								double cs_x, double cs_y, double cs_z, double cs_t, 
								long long max_x, long long max_y, long long max_z, long long max_t,
								long long regime, long long datatype,
								char* filename,
								char* header);// regime: 0-1D, 1-2D, 2-3D, 3-4D

private: static long long SaveToFileNCMPX(COMPLEX* data, long long sizex, long long sizey, long long sizez, long long sizet, 
								double cs_x, double cs_y, double cs_z, double cs_t, 
								long long max_x, long long max_y, long long max_z, long long max_t,
								long long regime,
								char* filename,
								char* header);// regime: 0-1D, 1-2D, 2-3D, 3-4D
private: static long long SaveToFileAPCMPX(COMPLEX* data, long long sizex, long long sizey, long long sizez, long long sizet, 
								double cs_x, double cs_y, double cs_z, double cs_t, 
								long long max_x, long long max_y, long long max_z, long long max_t,
								long long regime,
								char* filename,
								char* header);// regime: 0-1D, 1-2D, 2-3D, 3-4D
private: static long long SaveToFileReCMPX(COMPLEX* data, long long sizex, long long sizey, long long sizez, long long sizet, 
								double cs_x, double cs_y, double cs_z, double cs_t, 
								long long max_x, long long max_y, long long max_z, long long max_t,
								long long regime,
								char* filename,
								char* header);// regime: 0-1D, 1-2D, 2-3D, 3-4D
private: static long long SaveToFileImgCMPX(COMPLEX* data, long long sizex, long long sizey, long long sizez, long long sizet, 
								double cs_x, double cs_y, double cs_z, double cs_t, 
								long long max_x, long long max_y, long long max_z, long long max_t,
								long long regime,
								char* filename,
								char* header);// regime: 0-1D, 1-2D, 2-3D, 3-4D
private: static long long SaveToFileReal(float* data, long long sizex, long long sizey, long long sizez, long long sizet, 
								double cs_x, double cs_y, double cs_z, double cs_t, 
								long long max_x, long long max_y, long long max_z, long long max_t,
								long long regime,
								char* filename,
								char* header);// regime: 0-1D, 1-2D, 2-3D, 3-4D

};
#pragma managed





#endif