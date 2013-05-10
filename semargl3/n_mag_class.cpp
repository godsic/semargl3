#pragma unmanaged
#include "n_probe.h"
#include "n_mag_class.h"
#include "n_common_func.h"
#include "n_vfft.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <omp.h>
//#include <ppl.h>
#include <memory.h>
//using namespace Concurrency;


cMagnetization::cMagnetization(SIMPARAMS* params)
{
	// copy the simulations parameters
	SetSimulationParameters(params);

	// allocate the storage for the buffers
	long long size_xyzt_v1 = s_params.m_SizeX * s_params.m_SizeY * s_params.m_SizeZ * s_params.m_NumberOfTimeSteps;
	long long size_xyz_v3 = 3 * s_params.m_SizeX * s_params.m_SizeY * s_params.m_SizeZ; // 3 components vector of spatial distribution of M
	m_SizeOfDataBytes = sizeof(COMPLEX) * size_xyzt_v1;
	m_SizeOfDataElements = 2 * size_xyzt_v1;
	data = (COMPLEX*)new float[m_SizeOfDataElements];
	static_data = new float[size_xyz_v3];

	// initialize flags
	m_IsParametersLoaded = 1;
	m_IsKDomain = 0;
	m_IsFreqDomain = 0;
	m_IsAmpAndPhase = 0;
	m_IsLoaded = 0;
}
cMagnetization::cMagnetization()
{
	m_SizeOfDataBytes = 0;
	m_IsParametersLoaded = 0;
	m_SizeOfDataElements = 0;
	m_IsKDomain = 0;
	m_IsFreqDomain = 0;
	m_IsAmpAndPhase = 0;
	m_IsLoaded = 0;
}
cMagnetization::~cMagnetization()
{
	delete(data);
	delete(static_data);
	m_SizeOfDataBytes = 0;
	m_SizeOfDataElements = 0;
	m_IsKDomain = 0;
	m_IsFreqDomain = 0;
	m_IsAmpAndPhase = 0;
	m_IsLoaded = 0;
}

void cMagnetization::CleanBuffers()
{
	delete(this->data);
	delete(this->static_data);
	delete(this->avgdata);
	delete(this->avgdata_fft);
	delete(this->layer_buff_2d);
	delete(this->layer_buff_3d);

	this->m_SizeOfDataBytes = 0;
	this->m_SizeOfDataElements = 0;
	this->m_IsKDomain = 0;
	this->m_IsFreqDomain = 0;
	this->m_IsAmpAndPhase = 0;
	this->m_IsLoaded = 0;
}

long long cMagnetization::ValidateRealData()
{
	long long size_xyzt_v1 = (long long)s_params.m_SizeX * (long long)s_params.m_SizeY * (long long)s_params.m_SizeZ * (long long)s_params.m_NumberOfTimeSteps;
	for (long long i = 0; i < size_xyzt_v1;i++)
	{
		float Re = data[i].Re;
		float Img = data[i].Img;

		if(Re != Re) return 1;
		if(Img != Img) return 1;
		if(Img != 0.0f) return 1;
	}
	return 0;
}

long long cMagnetization::ValidateCMPXData()
{
	long long size_xyzt_v1 = (long long)s_params.m_SizeX * (long long)s_params.m_SizeY * (long long)s_params.m_SizeZ * (long long)s_params.m_NumberOfTimeSteps;
	for (long long i = 0; i < size_xyzt_v1;i++)
	{
		float Re = data[i].Re;
		float Img = data[i].Img;

		if(Re != Re) return 1;
		if(Img != Img) return 1;
	}
	return 0;
}

void cMagnetization::AllocateBuffers()
{
	long long size_xyzt_v1 = (long long)s_params.m_SizeX * (long long)s_params.m_SizeY * (long long)s_params.m_SizeZ * (long long)s_params.m_NumberOfTimeSteps;
	long long size_xyz_v3 = (long long)3 * (long long)s_params.m_SizeX * (long long)s_params.m_SizeY * (long long)s_params.m_SizeZ; // 3 components vector of spatial distribution of M
	m_SizeOfDataBytes = (long long)sizeof(COMPLEX) * size_xyzt_v1;
	m_SizeOfDataElements = (long long)2 * size_xyzt_v1;
	data = (COMPLEX*)new float[m_SizeOfDataElements];
	static_data = new float[size_xyz_v3];
}

void cMagnetization::AllocateAvgBuffer(long long sizex, long long sizey, long long sizez, long long sizet)
{
	long long size = (long long)2 * (long long)sizex * (long long)sizey * (long long)sizez * (long long)sizet;
	avgdata = (COMPLEX*) new float[size];
	m_asizeX = sizex;
	m_asizeY = sizey;
	m_asizeZ = sizez;
	m_asizeT = sizet;
}
void cMagnetization::AllocateAvgFFTBuffer(long long sizex, long long sizey, long long sizez, long long sizet)
{
	long long size = (long long)2 * (long long)sizex * (long long)sizey * (long long)sizez * (long long)sizet;
	avgdata_fft = (COMPLEX*) new float[size];
	m_asizeX = sizex;
	m_asizeY = sizey;
	m_asizeZ = sizez;
	m_asizeT = sizet;
}

void cMagnetization::Allocate2DLayerBuffer(long long sizex, long long sizey)
{
	m_lsizeX = sizex;
	m_lsizeY = sizey;
    long long size = (long long)2 * (long long)sizex * (long long)sizey;
	layer_buff_2d = (COMPLEX*)new float[size];
}

void cMagnetization::Allocate3DLayerBuffer(long long sizex, long long sizey, long long sizez)
{
	m_lsizeX = sizex;
	m_lsizeY = sizey;
	m_lsizeZ = sizez;

    long long size = (long long)2 * (long long)sizex * (long long)sizey * (long long)sizez;
	layer_buff_3d = (COMPLEX*)new float[size];
}

void cMagnetization::Destroy3DLayerBuffer()
{
	delete[] layer_buff_3d;
	//m_lsizeX = 0;
	//m_lsizeY = 0;
	m_lsizeZ = 0;
}

void cMagnetization::SetSimulationParameters(SIMPARAMS *sim_params)
{
	s_params.m_CellSizeX = sim_params->m_CellSizeX;
	s_params.m_CellSizeY = sim_params->m_CellSizeY;
	s_params.m_CellSizeZ = sim_params->m_CellSizeZ;

	s_params.m_MaxFrequency= sim_params->m_MaxFrequency;
	s_params.m_MaxInverseWavelengthX = sim_params->m_MaxInverseWavelengthX;
	s_params.m_MaxInverseWavelengthY = sim_params->m_MaxInverseWavelengthY;
	s_params.m_MaxInverseWavelengthZ = sim_params->m_MaxInverseWavelengthZ;

	s_params.m_MsCount = sim_params->m_MsCount;
	s_params.m_MsMax = sim_params->m_MsMax;

	s_params.m_NumberOfTimeSteps = sim_params->m_NumberOfTimeSteps;
    if (sim_params->m_pFolderWithTheData != NULL)
	{
		long long len = strlen(sim_params->m_pFolderWithTheData);
		//s_params.m_pFolderWithTheData = new char[len];
		strcpy(s_params.m_pFolderWithTheData, sim_params->m_pFolderWithTheData);
	}

	if (sim_params->m_pMIFFileName != NULL)
	{
		long long len = strlen(sim_params->m_pMIFFileName);
		//s_params.m_pMIFFileName = new char[len];
		strcpy(s_params.m_pMIFFileName, sim_params->m_pMIFFileName);
	}
	
	//s_params.m_pMs = new double[sim_params->m_MsCount];
	for (long long i=0;i<sim_params->m_MsCount;i++)
	{
		s_params.m_pMs[i] = sim_params->m_pMs[i];	
	}

	if (sim_params->m_pStaticFileName != NULL)
	{
		long long len = strlen(sim_params->m_pStaticFileName);
		//s_params.m_pStaticFileName = new char[len];
		strcpy(s_params.m_pStaticFileName, sim_params->m_pStaticFileName);
	}

	s_params.m_ResFrequency = sim_params->m_ResFrequency;
	s_params.m_ResInverseWavelengthX = sim_params->m_ResInverseWavelengthX;
	s_params.m_ResInverseWavelengthY = sim_params->m_ResInverseWavelengthY;
	s_params.m_ResInverseWavelengthZ = sim_params->m_ResInverseWavelengthZ;

	s_params.m_SimulationsTotalTime = sim_params->m_SimulationsTotalTime;
	s_params.m_SizeX = sim_params->m_SizeX;
	s_params.m_SizeY = sim_params->m_SizeY;
	s_params.m_SizeZ = sim_params->m_SizeZ;
	s_params.m_StageTime = sim_params->m_StageTime;

}

void cMagnetization::dbgDoDataAveraging()
{
	if (data==NULL) return;
	long long xyz_size = s_params.m_SizeX * s_params.m_SizeY * s_params.m_SizeZ;
	avgdata = (COMPLEX*)new float[s_params.m_NumberOfTimeSteps];
	float norm = 1.0 / xyz_size;
	for (long long k=0;k<s_params.m_NumberOfTimeSteps;k++)
	{		
		long long addr = k * xyz_size;
		double avg = 0.0;
		for (long long i=0;i<xyz_size;i++)
		{
			avg += data[addr+i].Re;	
		}
		avgdata[k].Re = (float)norm * (float)avg;
	}
}


void cMagnetization::SetParametersFlag()
{
	m_IsParametersLoaded = 1;
}
void cMagnetization::ResetParametersFlag()
{
	m_IsParametersLoaded = 0;
}
long long cMagnetization::GetParametersFlag()
{
	return m_IsParametersLoaded;
}

void cMagnetization::Do1DAveraging(long long axis)
{	
	const long long sx = cProbe::sizeX;
	const long long sy = cProbe::sizeY;
	const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;


	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	long long size = 0;
	double norm = 0;

	switch(axis)
	{
	case 0:
		// averaging along the X direction;
		size = sy * sz * s_params.m_NumberOfTimeSteps;
		avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

		norm = 1.0 / sx;

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long k = 0; k < sz; k++)
			{
				long long k1 = bz + k;
				for (long long j = 0; j < sy; j++)
				{
					long long j1 = by + j;
					double avg_re = 0.0;
					double avg_img = 0.0;
					for (long long i = 0; i <sx; i++)
					{
						long long i1 = bx + i;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
						avg_re += cProbe::probe[paddr] * data[daddr].Re;
						avg_img += cProbe::probe[paddr] * data[daddr].Img;
					}
					avg_re *= norm;
					avg_img *= norm;
					long long aaddr = p_addr_xyz_v1(sy, sz, j, k, t);
					avgdata[aaddr].Re = avg_re;
					avgdata[aaddr].Img = avg_img;
				}
				
			}
		}
		m_asizeX = sy;
		m_asizeY = sz;
		m_asizeZ = st;
		break;
	case 1:
		// averaging along the Y direction;
		size = sx * sz * s_params.m_NumberOfTimeSteps;
		avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

		norm = 1.0 / sy;

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long k = 0; k < sz; k++)
			{
				long long k1 = bz + k;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					double avg_re = 0.0;
					double avg_img = 0.0;
					for (long long j = 0; j < sy; j++)
					{	
						long long j1 = by + j;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
						avg_re += cProbe::probe[paddr] * data[daddr].Re;
						avg_img += cProbe::probe[paddr] * data[daddr].Img;
					}
					long long aaddr = p_addr_xyz_v1(sx, sz, i, k, t);
					avg_re *= norm;
					avg_img *= norm;
					avgdata[aaddr].Re = (float)avg_re;
					avgdata[aaddr].Img = (float)avg_img;
				}
				
			}
		}
		m_asizeX = sx;
		m_asizeY = sz;
		m_asizeZ = st;
		break;
	case 2:
		// averaging along the Z direction;
		size = sx * sy * s_params.m_NumberOfTimeSteps;
		avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

		norm = 1.0 / sz;

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long j = 0; j < sy; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					double avg_re = 0.0;
					double avg_img = 0.0;
					for (long long k = 0; k < sz; k++)
					{	
						long long k1 = bz + k;	
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
						avg_re += cProbe::probe[paddr] * data[daddr].Re;
						avg_img += cProbe::probe[paddr] * data[daddr].Img;
					}
					long long aaddr = p_addr_xyz_v1(sx, sy, i, j, t);
					avg_re *= norm;
					avg_img *= norm;
					avgdata[aaddr].Re = (float)avg_re;
					avgdata[aaddr].Img = (float)avg_img;
				}
				
			}
		}
		m_asizeX = sx;
		m_asizeY = sy;
		m_asizeZ = st;
		break;
	}
}

void cMagnetization::Do1DAveragingInplace(long long axis)
{

	// will write to bx, j, k; i, by, k; i, j, bz depends on the value of axis
	long long sx, sy, sz;
	if (m_isXavg == 1) sx = 1;
	else sx = cProbe::sizeX;

	if (m_isYavg == 1) sy = 1;
	else sy = cProbe::sizeY;

	if (m_isZavg == 1) sz = 1;
	else sz = cProbe::sizeZ;

	//const long long sx = cProbe::sizeX;
	//const long long sy = cProbe::sizeY;
	//const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;

	

	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	long long size = 0;
	double norm = 0.0;

	switch(axis)
	{
	case 0:
		// averaging along the X direction;

		norm = 1.0 / sx;

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long k = 0; k < sz; k++)
			{
				long long k1 = bz + k;
				for (long long j = 0; j < sy; j++)
				{
					long long j1 = by + j;
					double avg_re = 0.0;  //FLOAT?
					double avg_img = 0.0; //FLOAT?
					for (long long i = 0; i <sx; i++)
					{
						long long i1 = bx + i;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						avg_re += data[daddr].Re;
						avg_img += data[daddr].Img;
					}
					avg_re *= norm;
					avg_img *= norm;
					long long naddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, bx, j1, k1, t);
					data[naddr].Re = avg_re;
					data[naddr].Img = avg_img;
				}	
			}
		}

		m_isXavg = 1;
		break;
	case 1:
		// averaging along the Y direction;
		norm = 1.0 / sy;

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long k = 0; k < sz; k++)
			{
				long long k1 = bz + k;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					double avg_re = 0.0;
					double avg_img = 0.0;
					for (long long j = 0; j < sy; j++)
					{	
						long long j1 = by + j;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						avg_re += data[daddr].Re;
						avg_img += data[daddr].Img;
					}
					long long naddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, by, k1, t);
					avg_re *= norm;
					avg_img *= norm;
					data[naddr].Re = (float)avg_re;
					data[naddr].Img = (float)avg_img;
				}
				
			}
		}
		m_isYavg = 1;
		break;
	case 2:
		// averaging along the Z direction;
		norm = 1.0 / sz;

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long j = 0; j < sy; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					double avg_re = 0.0;
					double avg_img = 0.0;
					for (long long k = 0; k < sz; k++)
					{	
						long long k1 = bz + k;	
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						avg_re += data[daddr].Re;
						avg_img += data[daddr].Img;
					}
					long long naddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, bz, t);
					avg_re *= norm;
					avg_img *= norm;
					data[naddr].Re = (float)avg_re;
					data[naddr].Img = (float)avg_img;
				}
				
			}
		}
		m_isZavg = 1;
		break;
	}

}


void cMagnetization::Do1DAveragingInplaceParallel(long long axis)
{

	// will write to bx, j, k; i, by, k; i, j, bz depends on the value of axis
	long long sx, sy, sz;
	if (m_isXavg == 1) sx = 1;
	else sx = cProbe::sizeX;

	if (m_isYavg == 1) sy = 1;
	else sy = cProbe::sizeY;

	if (m_isZavg == 1) sz = 1;
	else sz = cProbe::sizeZ;

	//const long long sx = cProbe::sizeX;
	//const long long sy = cProbe::sizeY;
	//const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;

	

	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	long long size = 0;
	double norm = 0.0;

	switch(axis)
	{
	case 0:
		// averaging along the X direction;

		norm = 1.0 / sx;
		//parallel_for(long long(0), sy, [&](long long j)
#pragma omp parallel for
		for (long long j = 0; j < sy; j++)
		{
			long long j1 = by + j;
			for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
			{
				for (long long k = 0; k < sz; k++)
				{
					long long k1 = bz + k;
					double avg_re = 0.0;  //FLOAT?
					double avg_img = 0.0; //FLOAT?
					for (long long i = 0; i <sx; i++)
					{
						long long i1 = bx + i;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						avg_re += data[daddr].Re;
						avg_img += data[daddr].Img;
					}
					avg_re *= norm;
					avg_img *= norm;
					long long naddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, bx, j1, k1, t);
					data[naddr].Re = avg_re;
					data[naddr].Img = avg_img;
				}	
			}
		}//);

		m_isXavg = 1;
		break;
	case 1:
		// averaging along the Y direction;
		norm = 1.0 / sy;
		//parallel_for(long long (0), sz, [&](long long k)
#pragma omp parallel for
		for (long long k = 0; k < sz; k++)
		{
			long long k1 = bz + k;
			for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
			{	
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					double avg_re = 0.0;
					double avg_img = 0.0;
					for (long long j = 0; j < sy; j++)
					{	
						long long j1 = by + j;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						avg_re += data[daddr].Re;
						avg_img += data[daddr].Img;
					}
					long long naddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, by, k1, t);
					avg_re *= norm;
					avg_img *= norm;
					data[naddr].Re = (float)avg_re;
					data[naddr].Img = (float)avg_img;
				}
				
			}
		}//);
		m_isYavg = 1;
		break;
	case 2:
		// averaging along the Z direction;
		norm = 1.0 / sz;
		//parallel_for(long long(0), sy, [&](long long j)
#pragma omp parallel for
		for (long long j = 0; j < sy; j++)
		{
			long long j1 = by + j;
			for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
			{
			
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					double avg_re = 0.0;
					double avg_img = 0.0;
					for (long long k = 0; k < sz; k++)
					{	
						long long k1 = bz + k;	
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						avg_re += data[daddr].Re;
						avg_img += data[daddr].Img;
					}
					long long naddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, bz, t);
					avg_re *= norm;
					avg_img *= norm;
					data[naddr].Re = (float)avg_re;
					data[naddr].Img = (float)avg_img;
				}
				
			}
		}//);
		m_isZavg = 1;
		break;
	}

}




void cMagnetization::Do1DAveragingAmpInplace(long long axis)
{
		// will write to bx, j, k; i, by, k; i, j, bz depends on the value of axis

	/*const long long sx = cProbe::sizeX;
	const long long sy = cProbe::sizeY;
	const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;*/

	long long sx, sy, sz;
	if (m_isXavg == 1) sx = 1;
	else sx = cProbe::sizeX;

	if (m_isYavg == 1) sy = 1;
	else sy = cProbe::sizeY;

	if (m_isZavg == 1) sz = 1;
	else sz = cProbe::sizeZ;

	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	long long size = 0;
	double norm = 0.0;

	switch(axis)
	{
	case 0:
		// averaging along the X direction;

		norm = 1.0 / sx;

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long k = 0; k < sz; k++)
			{
				long long k1 = bz + k;
				for (long long j = 0; j < sy; j++)
				{
					long long j1 = by + j;
					double avg_re = 0.0;  //FLOAT?
					double avg_img = 0.0; //FLOAT?
					for (long long i = 0; i <sx; i++)
					{
						long long i1 = bx + i;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						float Re = data[daddr].Re;
						float Img = data[daddr].Img;

						float Amp = sqrtf(Re * Re + Img * Img);
						float Phz = atan2f(Img, Re);

						avg_re += Amp;
						avg_img += Phz;
					}
					avg_re *= norm;
					avg_img *= norm;
					long long naddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, bx, j1, k1, t);
					data[naddr].Re = avg_re;
					data[naddr].Img = avg_img;
				}	
			}
		}
		m_isXavg = 1;
		break;
	case 1:
		// averaging along the Y direction;
		norm = 1.0 / sy;

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long k = 0; k < sz; k++)
			{
				long long k1 = bz + k;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					double avg_re = 0.0;
					double avg_img = 0.0;
					for (long long j = 0; j < sy; j++)
					{	
						long long j1 = by + j;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						float Re = data[daddr].Re;
						float Img = data[daddr].Img;

						float Amp = sqrtf(Re * Re + Img * Img);
						float Phz = atan2f(Img, Re);

						avg_re += Amp;
						avg_img += Phz;
					}
					long long naddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, by, k1, t);
					avg_re *= norm;
					avg_img *= norm;
					data[naddr].Re = (float)avg_re;
					data[naddr].Img = (float)avg_img;
				}
				
			}
		}
		m_isYavg = 1;
		break;
	case 2:
		// averaging along the Z direction;
		norm = 1.0 / sz;

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long j = 0; j < sy; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					double avg_re = 0.0;
					double avg_img = 0.0;
					for (long long k = 0; k < sz; k++)
					{	
						long long k1 = bz + k;	
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						float Re = data[daddr].Re;
						float Img = data[daddr].Img;

						float Amp = sqrtf(Re * Re + Img * Img);
						float Phz = atan2f(Img, Re);

						avg_re += Amp;
						avg_img += Phz;
					}
					long long naddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, bz, t);
					avg_re *= norm;
					avg_img *= norm;
					data[naddr].Re = (float)avg_re;
					data[naddr].Img = (float)avg_img;
				}
				
			}
		}
		m_isZavg = 1;
		break;
	}
}
void cMagnetization::Do2DAveraging(long long axis)
{
	const long long sx = cProbe::sizeX;
	const long long sy = cProbe::sizeY;
	const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;


	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	long long size = 0;
	double norm = 0.0;

	switch(axis)
	{
	case 0:
		// averaging of the YZ plane;
		size = sx * s_params.m_NumberOfTimeSteps;
		avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

		norm = 1.0 / (sy*sz);

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long i = 0; i <sx; i++)	
			{
				long long i1 = bx + i;
				double avg_re = 0.0;
				double avg_img = 0.0;
				for (long long j = 0; j < sy; j++)
				{
					long long j1 = by + j;
					
					for (long long k = 0; k < sz; k++)
					{
						long long k1 = bz + k;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
						avg_re += cProbe::probe[paddr] * data[daddr].Re;
						avg_img += cProbe::probe[paddr] * data[daddr].Img;
					}
				}
				long long aaddr = p_addr_xy_v1(sx,i,t);
				avg_re *= norm;
				avg_img *= norm;	
				avgdata[aaddr].Re = (float)avg_re;
				avgdata[aaddr].Img = (float)avg_img;
				
			}
		}
		m_asizeX = sx;
		m_asizeY = 1;
		m_asizeZ = 1;
		m_asizeT = st;
		break;
	case 1:
		// averaging of the XZ plane;
		size = sy * s_params.m_NumberOfTimeSteps;
		avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

		norm = 1.0 / (sx*sz);

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long j = 0; j < sy; j++)			
			{
				long long j1 = by + j;
				double avg_re = 0.0;
				double avg_img = 0.0;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					for (long long k = 0; k < sz; k++)
					{
						long long k1 = bz + k;
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
						avg_re += cProbe::probe[paddr] * data[daddr].Re;
						avg_img += cProbe::probe[paddr] * data[daddr].Img;
					}
				}
				long long aaddr = p_addr_xy_v1(sy,j,t);
				avg_re *= norm;
				avg_img *= norm;	
				avgdata[aaddr].Re = (float)avg_re;
				avgdata[aaddr].Img = (float)avg_img;			
			}
		}
		m_asizeX = sy;
		m_asizeY = 1;
		m_asizeZ = 1;
		m_asizeT = st;
		break;
	case 2:
		// averaging of the XY plane;
		size = sz * s_params.m_NumberOfTimeSteps;
		avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

		norm = 1.0 / (sx*sy);

		for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
		{
			for (long long k = 0; k < sz; k++)				
			{
				long long k1 = bz + k;
				double avg_re = 0.0;
				double avg_img = 0.0;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;
					for (long long j = 0; j < sy; j++)
					{
						long long j1 = by + j;	
						long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
													s_params.m_SizeY, 
													s_params.m_SizeZ, i1, j1, k1, t);
						long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
						avg_re += cProbe::probe[paddr] * data[daddr].Re;
						avg_img += cProbe::probe[paddr] * data[daddr].Img;
					}
				}
				long long aaddr = p_addr_xy_v1(sz,k,t);
				avg_re *= norm;
				avg_img *= norm;	
				avgdata[aaddr].Re = (float)avg_re;
				avgdata[aaddr].Img = (float)avg_img;				
			}
		}
		m_asizeX = sz;
		m_asizeY = 1;
		m_asizeT = st;
		m_asizeZ = 1;
		break;
	}
}
void cMagnetization::Do3DAveraging()
{
	const long long sx = cProbe::sizeX;
	const long long sy = cProbe::sizeY;
	const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;


	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	// averaging of the XY plane;
	const long long size = s_params.m_NumberOfTimeSteps;
	avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

	const double norm = 1.0 / (sx*sy*sz);

	for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
	{
		double avg_re = 0.0;
		double avg_img = 0.0;
		for (long long k = 0; k < sz; k++)				
		{
			long long k1 = bz + k;
			for (long long j = 0; j < sy; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;	
					long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
												s_params.m_SizeY, 
												s_params.m_SizeZ, i1, j1, k1, t);
					long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
					avg_re += cProbe::probe[paddr] * data[daddr].Re;
					avg_img += cProbe::probe[paddr] * data[daddr].Img;
				}
			}			
		}
		avg_re *= norm;
		avg_img *= norm;	
		avgdata[t].Re = (float)avg_re;
		avgdata[t].Img = (float)avg_img;	
	}
	m_asizeX = 1;
	m_asizeY = 1;
	m_asizeZ = st;
}

void cMagnetization::Do3DAveragingBW(float kxa, float kxb, float kya, float kyb, float kza, float kzb)
{
	const long long sx = cProbe::sizeX;
	const long long sy = cProbe::sizeY;
	const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;
	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	long long hsx = sx / 2;
	long long hsy = sy / 2;
	long long hsz = sz / 2;

	long long bwxa = (long long)(kxa * hsx);
	long long bwxb = (long long)(kxb * hsx);

	long long bwya = (long long)(kya * hsy);
	long long bwyb = (long long)(kyb * hsy);

	long long bwza = (long long)(kza * hsz);
	long long bwzb = (long long)(kzb * hsz);

	long long bwx = bwxa + bwxb;
	long long bwy = bwya + bwyb;
	long long bwz = bwza + bwzb;
    
	long long sxa = bx + (hsx - bwxa);
	long long sxb = bx + (hsx + bwxb);

	long long sya = by + (hsy - bwya);
	long long syb = by + (hsy + bwyb);

	long long sza = bz + (hsz - bwza);
	long long szb = bz + (hsz + bwzb);

	bwx = (bwx==0) ? 1 : bwx;
	bwy = (bwy==0) ? 1 : bwy;
	bwz = (bwz==0) ? 1 : bwz;

	// averaging of the XY plane;
	const long long size = st;
	avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

	const double norm = 1.0 / (bwx*bwy*bwz);
	for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
	{
		double avg_re = 0.0;
		double avg_img = 0.0;
		for (long long k = 0; k < bwz; k++)				
		{
			long long k1 = sza + k;
			for (long long j = 0; j < bwy; j++)
			{
				long long j1 = sya + j;
				for (long long i = 0; i < bwx; i++)	
				{
					long long i1 = sxa + i;	
					long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
												s_params.m_SizeY, 
												s_params.m_SizeZ, i1, j1, k1, t);
					long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
					avg_re += cProbe::probe[paddr] * data[daddr].Re;
					avg_img += cProbe::probe[paddr] * data[daddr].Img;
				}
			}			
		}
		avg_re *= norm;
		avg_img *= norm;	
		avgdata[t].Re = (float)avg_re;
		avgdata[t].Img = (float)avg_img;	
	}
	m_asizeX = 1;
	m_asizeY = 1;
	m_asizeZ = st;


}
void cMagnetization::Do3DAveragingBWCMPX(float kxa, float kxb, float kya, float kyb, float kza, float kzb)
{
	const long long sx = cProbe::sizeX;
	const long long sy = cProbe::sizeY;
	const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;
	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	long long hsx = sx / 2;
	long long hsy = sy / 2;
	long long hsz = sz / 2;

	long long bwxa = (long long)(kxa * hsx);
	long long bwxb = (long long)(kxb * hsx);

	long long bwya = (long long)(kya * hsy);
	long long bwyb = (long long)(kyb * hsy);

	long long bwza = (long long)(kza * hsz);
	long long bwzb = (long long)(kzb * hsz);

	long long bwx = bwxa + bwxb;
	long long bwy = bwya + bwyb;
	long long bwz = bwza + bwzb;
    
	long long sxa = bx + (hsx - bwxa);
	long long sxb = bx + (hsx + bwxb);

	long long sya = by + (hsy - bwya);
	long long syb = by + (hsy + bwyb);

	long long sza = bz + (hsz - bwza);
	long long szb = bz + (hsz + bwzb);

	bwx = (bwx==0) ? 1 : bwx;
	bwy = (bwy==0) ? 1 : bwy;
	bwz = (bwz==0) ? 1 : bwz;

	// averaging of the XY plane;
	const long long size = st;
	avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

	const double norm = 1.0 / (bwx*bwy*bwz);
	for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
	{
		double avg_re = 0.0;
		double avg_img = 0.0;
		for (long long k = 0; k < bwz; k++)				
		{
			long long k1 = sza + k;
			for (long long j = 0; j < bwy; j++)
			{
				long long j1 = sya + j;
				for (long long i = 0; i < bwx; i++)	
				{
					long long i1 = sxa + i;	
					long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
												s_params.m_SizeY, 
												s_params.m_SizeZ, i1, j1, k1, t);
					long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
					float Re = cProbe::probe[paddr] * data[daddr].Re;
					float Img = cProbe::probe[paddr] * data[daddr].Img;
					float Amp = sqrtf(Re*Re + Img*Img);
					float Phz = atan2f(Img, Re);
					avg_re += Amp;
					avg_img += Phz;
				}
			}			
		}
		avg_re *= norm;
		avg_img *= norm;	
		avgdata[t].Re = (float)avg_re;
		avgdata[t].Img = (float)avg_img;	
	}
	m_asizeX = 1;
	m_asizeY = 1;
	m_asizeZ = st;


}

void cMagnetization::Do3DAveragingBWCMPXParallel(float kxa, float kxb, float kya, float kyb, float kza, float kzb)
{
	const long long sx = cProbe::sizeX;
	const long long sy = cProbe::sizeY;
	const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;
	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	long long hsx = sx / 2;
	long long hsy = sy / 2;
	long long hsz = sz / 2;

	long long bwxa = (long long)(kxa * hsx);
	long long bwxb = (long long)(kxb * hsx);

	long long bwya = (long long)(kya * hsy);
	long long bwyb = (long long)(kyb * hsy);

	long long bwza = (long long)(kza * hsz);
	long long bwzb = (long long)(kzb * hsz);

	long long bwx = bwxa + bwxb;
	long long bwy = bwya + bwyb;
	long long bwz = bwza + bwzb;
    
	long long sxa = bx + (hsx - bwxa);
	long long sxb = bx + (hsx + bwxb);

	long long sya = by + (hsy - bwya);
	long long syb = by + (hsy + bwyb);

	long long sza = bz + (hsz - bwza);
	long long szb = bz + (hsz + bwzb);

	bwx = (bwx==0) ? 1 : bwx;
	bwy = (bwy==0) ? 1 : bwy;
	bwz = (bwz==0) ? 1 : bwz;

	// averaging of the XY plane;
	const long long size = st;
	avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

	const double norm = 1.0 / (bwx*bwy*bwz);

#pragma omp parallel for
	for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
	{
		double avg_re = 0.0;
		double avg_img = 0.0;
		for (long long k = 0; k < bwz; k++)				
		{
			long long k1 = sza + k;
			for (long long j = 0; j < bwy; j++)
			{
				long long j1 = sya + j;
				for (long long i = 0; i < bwx; i++)	
				{
					long long i1 = sxa + i;	
					long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
												s_params.m_SizeY, 
												s_params.m_SizeZ, i1, j1, k1, t);
					long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
					float Re = cProbe::probe[paddr] * data[daddr].Re;
					float Img = cProbe::probe[paddr] * data[daddr].Img;
					float Amp = sqrtf(Re*Re + Img*Img);
					float Phz = atan2f(Img, Re);
					avg_re += Amp;
					avg_img += Phz;
				}
			}			
		}
		avg_re *= norm;
		avg_img *= norm;	
		avgdata[t].Re = (float)avg_re;
		avgdata[t].Img = (float)avg_img;	
	}
	m_asizeX = 1;
	m_asizeY = 1;
	m_asizeZ = st;


}


void cMagnetization::Do3DAveragingAmp()
{
	const long long sx = cProbe::sizeX;
	const long long sy = cProbe::sizeY;
	const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;


	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	// averaging of the XY plane;
	const long long size = s_params.m_NumberOfTimeSteps;
	avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

	const double norm = 1.0 / (sx*sy*sz);

	for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
	{
		double avg_re = 0.0;
		double avg_img = 0.0;
		for (long long k = 0; k < sz; k++)				
		{
			long long k1 = bz + k;
			for (long long j = 0; j < sy; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;	
					long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
												s_params.m_SizeY, 
												s_params.m_SizeZ, i1, j1, k1, t);
					long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
					float Re = cProbe::probe[paddr] * data[daddr].Re;
					float Img = cProbe::probe[paddr] * data[daddr].Img;
					float amp = sqrtf(Re * Re + Img * Img);
					float phase = atan2f(Img, Re);
					avg_re += amp;
					avg_img += phase;
				}
			}			
		}
		avg_re *= norm;
		avg_img *= norm;	
		avgdata[t].Re = (float)avg_re;
		avgdata[t].Img = (float)avg_img;	
	}
	m_asizeX = 1;
	m_asizeY = 1;
	m_asizeZ = st;
}

void cMagnetization::Do3DAveragingAmpParallel()
{
	const long long sx = cProbe::sizeX;
	const long long sy = cProbe::sizeY;
	const long long sz = cProbe::sizeZ;
	const long long st = s_params.m_NumberOfTimeSteps;


	const long long bx = cProbe::X0;
	const long long by = cProbe::Y0;
	const long long bz = cProbe::Z0;

	// averaging of the XY plane;
	const long long size = s_params.m_NumberOfTimeSteps;
	avgdata = (COMPLEX*)new float[2 * size]; // 2 for complex!

	const double norm = 1.0 / (sx*sy*sz);
#pragma omp parallel for
	for (long long t = 0; t < s_params.m_NumberOfTimeSteps; t++)
	{
		double avg_re = 0.0;
		double avg_img = 0.0;
		for (long long k = 0; k < sz; k++)				
		{
			long long k1 = bz + k;
			for (long long j = 0; j < sy; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i <sx; i++)	
				{
					long long i1 = bx + i;	
					long long daddr = p_addr_xyzt_v1(s_params.m_SizeX, 
												s_params.m_SizeY, 
												s_params.m_SizeZ, i1, j1, k1, t);
					long long paddr = p_addr_xyz_v1(sx,sy,i,j,k);
					float Re = cProbe::probe[paddr] * data[daddr].Re;
					float Img = cProbe::probe[paddr] * data[daddr].Img;
					float amp = sqrtf(Re * Re + Img * Img);
					float phase = atan2f(Img, Re);
					avg_re += amp;
					avg_img += phase;
				}
			}			
		}
		avg_re *= norm;
		avg_img *= norm;	
		avgdata[t].Re = (float)avg_re;
		avgdata[t].Img = (float)avg_img;	
	}
	m_asizeX = 1;
	m_asizeY = 1;
	m_asizeZ = st;
}

void cMagnetization::Get2DFFTFromAveragedData()
{
	double scale = 1.0;
	long long sizex = m_asizeX;
	long long sizey = m_asizeT;
	long long size = sizex * sizey;
	long long size_cmpx = 2 * size;
	long long size_byte = sizeof(float) * size_cmpx;

	AllocateAvgFFTBuffer(sizex, 1, 1, sizey);

	//memcpy(avgdata_fft, avgdata, size_byte);

	int error = 0;
	long long commsize = 5 * sizey + 200;
	if (cFFT::m_IsRectWindow != 1) cFFT::ApplyWindow2D((COMPLEX*)&avgdata[0].Re, m_asizeX);
	long long size_tbuf = 2 * sizey;

	COMPLEX* comm = (COMPLEX*)new float[2 * commsize];	
	COMPLEX* tbuf = (COMPLEX*)new float[size_tbuf];

	cFFT::InitZFFT1D(sizey, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

	for (long long i = 0; i < sizex; i++)
	{
		for (long long t = 0 ; t < sizey; t++)
		{
			long long addr = p_addr_xy_v1(sizex, i, t);
			tbuf[t].Re = avgdata[addr].Re;
			tbuf[t].Img = avgdata[addr].Img;
		}

		cFFT::ZFFT1D(sizey, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

		for (long long t = 0 ; t < sizey; t++)
		{
			long long addr = p_addr_xy_v1(sizex, i, t);
			avgdata_fft[addr].Re = tbuf[t].Re ;
			avgdata_fft[addr].Img = tbuf[t].Img;
		}
	}
}

void cMagnetization::Get2DSpatialLayer(long long plane, long long timestep, long long depth)
{
	long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;

	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	switch(plane)
	{
	case 0:
		// XY
		Allocate2DLayerBuffer(sizex, sizey);
		for (long long j = 0; j < sizey; j++)
		{
			long long j1 = by + j;
			for (long long i = 0; i < sizex; i++)
			{
				long long i1 = bx + i;
				long long addr = p_addr_xyzt_v1(s_params.m_SizeX,
											s_params.m_SizeY,
											s_params.m_SizeZ, i1, j1, depth, timestep);
				long long laddr = i + j * sizex;
				layer_buff_2d[laddr].Re = data[addr].Re;
				layer_buff_2d[laddr].Img = data[addr].Img;
			}
		}
		break;
	case 1:
		// XZ
		Allocate2DLayerBuffer(sizex, sizez);
		for (long long k = 0; k < sizez; k++)
		{
			long long k1 = bz + k;
			for (long long i = 0; i < sizex; i++)
			{
				long long i1 = bx + i;
				long long addr = p_addr_xyzt_v1(s_params.m_SizeX,
											s_params.m_SizeY,
											s_params.m_SizeZ, i1, depth, k1, timestep);
				long long laddr = i + k * sizex;
				layer_buff_2d[laddr].Re = data[addr].Re;
				layer_buff_2d[laddr].Img = data[addr].Img;
			}
		}
		break;
	case 2:
		// XZ
		Allocate2DLayerBuffer(sizey, sizez);
		for (long long k = 0; k < sizez; k++)
		{
			long long k1 = bz + k;
			for (long long j = 0; j < sizey; j++)
			{
				long long j1 = by + j;	
				long long addr = p_addr_xyzt_v1(s_params.m_SizeX,
											s_params.m_SizeY,
											s_params.m_SizeZ, depth, j1, k1, timestep);
				long long laddr = j + k * sizey;
				layer_buff_2d[laddr].Re = data[addr].Re;
				layer_buff_2d[laddr].Img = data[addr].Img;
			}
		}
		break;
	}
}
void cMagnetization::Get3DSpatialLayer(long long timestep)
{
	long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;

	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;


	Allocate3DLayerBuffer(sizex, sizey, sizez);
	for (long long k = 0; k < sizez; k++)
	{
		long long k1 = bz + k;
		for (long long j = 0; j < sizey; j++)
		{
			long long j1 = by + j;
			for (long long i = 0; i < sizex; i++)
			{
				long long i1 = bx + i;
				long long addr = p_addr_xyzt_v1(s_params.m_SizeX,
											s_params.m_SizeY,
											s_params.m_SizeZ, i1, j1, k1, timestep);

				long long laddr = p_addr_xyz_v1(sizex, sizey, i, j, k);

				layer_buff_3d[laddr].Re = data[addr].Re;
				layer_buff_3d[laddr].Img = data[addr].Img;
			}
		}
	}
}
void cMagnetization::DoF2A(long long avgmethod)
{
		// FFT Along the T
		DoFFTTParallel();
		//DoFFTT();
		// Averaging XYZT->T
		switch(avgmethod)
		{
		case 0:
			Do3DAveraging();
			break;
		case 1:
			Do3DAveragingAmpParallel();
			//Do3DAveragingAmp();
			break;
		}
		m_IsFreqDomain = 1;
};

void cMagnetization::DoA2F()
{
	Do3DAveraging();
	long long sizet = s_params.m_NumberOfTimeSteps;
	int error = 0;
	long long commsize = 5 * sizet + 200;
	if (cFFT::m_IsRectWindow != 1) cFFT::ApplyWindow1D((COMPLEX*)&avgdata[0].Re);
	COMPLEX* comm = (COMPLEX*)new float[2 * commsize];
	long long size_tbuf = 2 * sizet;
	COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];

	cFFT::InitZFFT1D(sizet, (COMPLEX*)&avgdata[0].Re, (COMPLEX*)&comm[0].Re, &error);
	cFFT::ZFFT1D(sizet, (COMPLEX*)&avgdata[0].Re, (COMPLEX*)&comm[0].Re, &error);
}

// FFT-n

void cMagnetization::Do3DFFT()
{
	// 3D spatial FFT at each point of time

	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	//long long sizex = cProbe::sizeX;
	//long long sizey = cProbe::sizeY;
	//long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * (sizex + sizey + sizez) + 150;
	//long long size_tbuf = 2 * sizet;

	COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
	//COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];
	long long addr =  p_addr_xyzt_v1(dsizex, dsizey, dsizez, bx, by, bz, 0);
	cFFT::InitZFFT3Df(sizex, sizey, sizez, dsizex, dsizey, dsizez, commsize, 1.0, (COMPLEX*)&data[addr].Re, comm, NULL, &error);
	for (int p = 0; p < sizet; p++)
	{
		long long daddr =  p_addr_xyzt_v1(dsizex, dsizey, dsizez, bx, by, bz, p);
		cFFT::ZFFT3Df(sizex, sizey, sizez, dsizex, dsizey, dsizez, commsize, 1.0, (COMPLEX*)&data[daddr].Re, comm, NULL, &error);
	}
	delete[] (float*)comm;

}
void cMagnetization::Do3DFFTParallel()
{
	// 3D spatial FFT at each point of time

	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	//long long sizex = cProbe::sizeX;
	//long long sizey = cProbe::sizeY;
	//long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	
	long long commsize = sizex * sizey * sizez + 4 * (sizex + sizey + sizez) + 300;//L*M*N + 4*(L+M+N) + 300//5 * (sizex + sizey + sizez) + 150;
	// allocate one huge buffer for communication
	int nt = omp_get_max_threads();
	int init = 0;
	int err = 0;
	COMPLEX* comm = (COMPLEX*)new float[2 * commsize * nt];
	long long addr =  p_addr_xyzt_v1(dsizex, dsizey, dsizez, bx, by, bz, 0);
	//Performance penalty on NUMA!
	for (int i = 0; i < nt; i++)
	{
		cFFT::InitZFFT3Df(sizex, sizey, sizez, dsizex, dsizey, dsizez, commsize, 1.0, (COMPLEX*)&data[addr].Re, (COMPLEX*)&comm[i * commsize].Re, NULL, &err);
	}

#pragma omp parallel for default(shared) firstprivate(err)
	for (long long  p = 0; p < sizet; p++)
	{
		int ii = omp_get_thread_num();
		long long daddr =  p_addr_xyzt_v1(dsizex, dsizey, dsizez, bx, by, bz, p);
		cFFT::ZFFT3Df(sizex, sizey, sizez, dsizex, dsizey, dsizez, commsize, 1.0, (COMPLEX*)&data[daddr].Re, (COMPLEX*)&comm[ii * commsize].Re, NULL, &err);
	}
	delete[] (float*)comm;
}

void cMagnetization::DoFFTT()
{
	// temporal FFT and each particular X,Y,Z

	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	//long long sizex = cProbe::sizeX;
	//long long sizey = cProbe::sizeY;
	//long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * sizet + 200;
	if (cFFT::m_IsRectWindow != 1) cFFT::ApplyWindow4D((COMPLEX*)&data[0].Re, bx, by, bz, sizex, sizey, sizez,
														dsizex,
														dsizey,
														dsizez);
	long long size_tbuf = 2 * sizet;

	COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
	COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];

	cFFT::InitZFFT1D(sizet, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

	for (long long k = 0; k < sizez; k++)
	{
		long long k1 = bz + k;
		for (long long j = 0; j < sizey; j++)
		{
			long long j1 = by + j;
			for (long long i = 0; i < sizex; i++)
			{
				long long i1 = bx + i;
				long long paddr = p_addr_xyz_v1(sizex, sizey, i, j, k);
				float probe = cProbe::probe[paddr];

				for (long long p = 0; p < sizet; p++)
				{
					long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					
					tbuf[p].Re = data[daddr].Re * probe; 
					tbuf[p].Img = data[daddr].Img * probe;
				}

				cFFT::ZFFT1D(sizet, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

				for (long long p = 0; p < sizet;p++)
				{
					long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					data[daddr].Re = tbuf[p].Re;
					data[daddr].Img = tbuf[p].Img;
				}
				
			}
		}
	}
}

void cMagnetization::DoFFTTParallel()
{
	// temporal FFT and each particular X,Y,Z

	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	//long long sizex = cProbe::sizeX;
	//long long sizey = cProbe::sizeY;
	//long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	
	long long commsize = 5 * sizet + 200;
	if (cFFT::m_IsRectWindow != 1) cFFT::ApplyWindow4D((COMPLEX*)&data[0].Re, bx, by, bz, sizex, sizey, sizez,
														dsizex,
														dsizey,
														dsizez);
	long long size_tbuf = 2 * sizet;

	
	//COMPLEX *comma = (COMPLEX*)new float[2 * commsize];
	//COMPLEX *tbufa = (COMPLEX*)new float[size_tbuf];
	int err = 0;
	//cFFT::InitZFFT1D(sizet, (COMPLEX*)&tbufa[0].Re, (COMPLEX*)&comma[0].Re, &errora);

//
	//parallel_for(long long(0), sizey,[&](long long j)
	int nt = omp_get_max_threads();
	COMPLEX *comm = (COMPLEX*)new float[2 * commsize * nt];
	COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf * nt];
	for (int i = 0; i < nt; i++)
	{
		cFFT::InitZFFT1D(sizet, (COMPLEX*)&tbuf[i * sizet].Re, (COMPLEX*)&comm[i * commsize].Re, &err);
	}
#pragma omp parallel for default(shared) firstprivate(err)
	for (long long j = 0; j < sizey; j++)
	{
		long long j1 = by + j;
		long long ii = (long long)omp_get_thread_num();
		long long tbc = sizet * ii;
		long long cbc = commsize * ii;

		for (long long k = 0; k < sizez; k++)
		{	
			long long k1 = bz + k;	

			for (long long i = 0; i < sizex; i++)
			{	
				
				long long i1 = bx + i;
				long long paddr = p_addr_xyz_v1(sizex, sizey, i, j, k);
				float probe = cProbe::probe[paddr];
 
				for (long long p = 0; p < sizet; p++)
				{
					long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					
					tbuf[p + tbc].Re = data[daddr].Re * probe; 
					tbuf[p + tbc].Img = data[daddr].Img * probe;
				}

				cFFT::ZFFT1D(sizet, (COMPLEX*)&tbuf[tbc].Re, (COMPLEX*)&comm[cbc].Re, &err);

				for (long long p = 0; p < sizet;p++)
				{
					long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					data[daddr].Re = tbuf[p + tbc].Re;
					data[daddr].Img = tbuf[p + tbc].Img;
				}
				
			}
		}
	}

	delete[] (float*)comm;
	delete[] (float*)tbuf;
}
void cMagnetization::DoFFTTMParallel()
{
	// temporal FFT and each particular X,Y,Z

	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	//long long sizex = cProbe::sizeX;
	//long long sizey = cProbe::sizeY;
	//long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	
	long long commsize = 5 * sizet + 200;
	if (cFFT::m_IsRectWindow != 1) cFFT::ApplyWindow4D((COMPLEX*)&data[0].Re, bx, by, bz, sizex, sizey, sizez,
														dsizex,
														dsizey,
														dsizez);
	long long size_tbuf = 2 * sizet;
	int err = 0;
	int sxyz = dsizex * dsizey * dsizez;
	COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
	cFFT::InitZFFT1DM(sizet, sxyz, sxyz, 1, data, comm, &err);
	cFFT::ZFFT1DM(sizet, sxyz, sxyz, 1, data, comm, &err);
}

void cMagnetization::DoFFTX()
{
	// FFT along X axis and each particular X,Y,T
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;

	long long size = sizex;				// CRUCIAL POINT
	long long commsize = 5 * size+ 200;
	long long size_tbuf = 2 * size;

	COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
	COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];

	cFFT::InitZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

	for (long long p = 0; p < sizet; p++)
	{
		for (long long k = 0; k < sizez; k++)
		{
			long long k1 = bz + k;
			for (long long j = 0; j < sizey; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					long long paddr = p_addr_xyz_v1(sizex, sizey, i, j, k);
					float probe = cProbe::probe[paddr];	
					long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);	
					tbuf[i].Re = data[daddr].Re * probe; 
					tbuf[i].Img = data[daddr].Img * probe;
				}

				cFFT::ZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

				for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					data[daddr].Re = tbuf[i].Re;
					data[daddr].Img = tbuf[i].Img;
				}	
			}
		}
	}
}

void cMagnetization::DoFFTXParallel()
{
	// FFT along X axis and each particular X,Y,T
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	//int error = 0;

	long long size = sizex;				// CRUCIAL POINT
	long long commsize = 5 * size+ 200;
	long long size_tbuf = 2 * size;

	//COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
	//COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];

	//cFFT::InitZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);


	//parallel_for(long long(0), sizey,[&](long long j)
#pragma omp parallel for//#pragma omp parallel for
for (long long j = 0; j < sizey; j++)
	{
		long long j1 = by + j;
		int error = 0;
		COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
		COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];

		cFFT::InitZFFT1DSimple(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);
		
		for (long long p = 0; p < sizet; p++)
		{
			
			for (long long k = 0; k < sizez; k++)
			{
						
				
				long long k1 = bz + k;
				for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					long long paddr = p_addr_xyz_v1(sizex, sizey, i, j, k);
					float probe = cProbe::probe[paddr];	
					long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);	
					tbuf[i].Re = data[daddr].Re * probe; 
					tbuf[i].Img = data[daddr].Img * probe;
				}

				cFFT::ZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

				for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					data[daddr].Re = tbuf[i].Re;
					data[daddr].Img = tbuf[i].Img;
				}
			}
		}
		delete[] (float*)comm;
		delete[] (float*)tbuf;
	}//);
}


void cMagnetization::DoFFTY()
{
	// FFT along Y axis and each particular X,Z,T
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;

	long long size = sizey;				// CRUCIAL POINT
	long long commsize = 5 * size+ 200;
	long long size_tbuf = 2 * size;

	COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
	COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];

	cFFT::InitZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

	for (long long p = 0; p < sizet; p++)
	{
		for (long long k = 0; k < sizez; k++)
		{
			long long k1 = bz + k;
			for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					for (long long j = 0; j < sizey; j++)
					{
						long long j1 = by + j;	
						long long paddr = p_addr_xyz_v1(sizex, sizey, i, j, k);
						float probe = cProbe::probe[paddr];	
						long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);	
						tbuf[j].Re = data[daddr].Re * probe; 
						tbuf[j].Img = data[daddr].Img * probe;
					}

					cFFT::ZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

					for (long long j = 0; j < sizey; j++)
					{
						long long j1 = by + j;
						long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						data[daddr].Re = tbuf[j].Re;
						data[daddr].Img = tbuf[j].Img;
					}	
			}
		}
	}
}

void cMagnetization::DoFFTYParallel()
{
	// FFT along Y axis and each particular X,Z,T
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	

	long long size = sizey;				// CRUCIAL POINT
	long long commsize = 5 * size+ 200;
	long long size_tbuf = 2 * size;

	

	//parallel_for(long long(0), sizez,[&](long long k)
#pragma omp parallel for
	for (long long k = 0; k < sizez; k++)
	{
		long long k1 = bz + k;
		int error = 0;
		COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
		COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];
		cFFT::InitZFFT1DSimple(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);
		for (long long p = 0; p < sizet; p++)
		{
			for (long long i = 0; i < sizex; i++)
				{					
					long long i1 = bx + i;
					for (long long j = 0; j < sizey; j++)
					{
						long long j1 = by + j;	
						long long paddr = p_addr_xyz_v1(sizex, sizey, i, j, k);
						float probe = cProbe::probe[paddr];	
						long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);	
						tbuf[j].Re = data[daddr].Re * probe; 
						tbuf[j].Img = data[daddr].Img * probe;
					}

					cFFT::ZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

					for (long long j = 0; j < sizey; j++)
					{
						long long j1 = by + j;
						long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						data[daddr].Re = tbuf[j].Re;
						data[daddr].Img = tbuf[j].Img;
					}	
			}
		}
		delete[] (float*)comm;
		delete[] (float*)tbuf;
	}//);
}


void cMagnetization::DoFFTZ()
{
	// FFT along Z axis and each particular X, Y, T
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;

	long long size = sizez;				// CRUCIAL POINT
	long long commsize = 5 * size+ 200;
	long long size_tbuf = 2 * size;

	COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
	COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];

	cFFT::InitZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

	for (long long p = 0; p < sizet; p++)
	{
		for (long long j = 0; j < sizey; j++)
		{
			long long j1 = by + j;	
			for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					for (long long k = 0; k < sizez; k++)
					{
						long long k1 = bz + k;	
						long long paddr = p_addr_xyz_v1(sizex, sizey, i, j, k);
						float probe = cProbe::probe[paddr];	
						long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);	
						tbuf[k].Re = data[daddr].Re * probe; 
						tbuf[k].Img = data[daddr].Img * probe;
					}

					cFFT::ZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

					for (long long k = 0; k < sizez; k++)
					{
						long long k1 = bz + k;
						long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						data[daddr].Re = tbuf[k].Re;
						data[daddr].Img = tbuf[k].Img;
					}	
			}
		}
	}
}

void cMagnetization::DoFFTZParallel()
{
	// FFT along Z axis and each particular X, Y, T
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	

	long long size = sizez;				// CRUCIAL POINT
	long long commsize = 5 * size+ 200;
	long long size_tbuf = 2 * size;

	

//#pragma omp parallel for
	//parallel_for(long long(0), sizey,[&](long long j)
#pragma omp parallel for
	for (long long j = 0; j < sizey; j++)
	{
		long long j1 = by + j;
		int error = 0;
		COMPLEX *comm = (COMPLEX*)new float[2 * commsize];
		COMPLEX *tbuf = (COMPLEX*)new float[size_tbuf];
		cFFT::InitZFFT1DSimple(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

		for (long long p = 0; p < sizet; p++)
		{

			for (long long i = 0; i < sizex; i++)
				{
					
					long long i1 = bx + i;
					for (long long k = 0; k < sizez; k++)
					{
						long long k1 = bz + k;	
						long long paddr = p_addr_xyz_v1(sizex, sizey, i, j, k);
						float probe = cProbe::probe[paddr];	
						long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);	
						tbuf[k].Re = data[daddr].Re * probe; 
						tbuf[k].Img = data[daddr].Img * probe;
					}

					cFFT::ZFFT1D(size, (COMPLEX*)&tbuf[0].Re, (COMPLEX*)&comm[0].Re, &error);

					for (long long k = 0; k < sizez; k++)
					{
						long long k1 = bz + k;
						long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						data[daddr].Re = tbuf[k].Re;
						data[daddr].Img = tbuf[k].Img;
					}	

			}
		}
		delete[] (float*)comm;
		delete[] (float*)tbuf;
	}//);
}

void cMagnetization::DoShiftedFormT()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * sizet + 200;

	long long size = sizet;
	long long hsize = size/2;

	for (long long k = 0; k < sizez; k++)
	{
		long long k1 = bz + k;
		for (long long j = 0; j < sizey; j++)
		{
			long long j1 = by + j;
			for (long long i = 0; i < sizex; i++)
			{
				long long i1 = bx + i;
				for (long long p = 0; p < hsize; p++)
				{
					long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, hsize + p);
					
					float Re = data[daddr_l].Re;
					float Img = data[daddr_l].Img;

					data[daddr_l].Re = data[daddr_r].Re; 
					data[daddr_l].Img = data[daddr_r].Img;
					data[daddr_r].Re = Re;
					data[daddr_r].Img = Img;

				}	
			}
		}
	}
}

void cMagnetization::DoShiftedFormTParallel()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * sizet + 200;

	long long size = sizet;
	long long hsize = size/2;
	if (sizez > 1)
	{
		//parallel_for(long long(0), sizez, [&](long long k)
#pragma omp parallel for
		for (long long k = 0; k < sizez; k++)
		{
			long long k1 = bz + k;
			for (long long j = 0; j < sizey; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					for (long long p = 0; p < hsize; p++)
					{
						long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, hsize + p);
					
						float Re = data[daddr_l].Re;
						float Img = data[daddr_l].Img;

						data[daddr_l].Re = data[daddr_r].Re; 
						data[daddr_l].Img = data[daddr_r].Img;
						data[daddr_r].Re = Re;
						data[daddr_r].Img = Img;

					}	
				}
			}
		}//);
	}
	else
	{
		//parallel_for(long long(0), sizey, [&](long long j)
#pragma omp parallel for
		for (long long j = 0; j < sizey; j++)
		{	
			long long j1 = by + j;
			for (long long k = 0; k < sizez; k++)
			{
				long long k1 = bz + k;	
				for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					for (long long p = 0; p < hsize; p++)
					{
						long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, hsize + p);
					
						float Re = data[daddr_l].Re;
						float Img = data[daddr_l].Img;

						data[daddr_l].Re = data[daddr_r].Re; 
						data[daddr_l].Img = data[daddr_r].Img;
						data[daddr_r].Re = Re;
						data[daddr_r].Img = Img;

					}	
				}
			}
		}//);
	}
}

void cMagnetization::DoShiftedFormX()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * sizet + 200;

	long long size = sizex;
	long long hsize = size/2;
	for (long long p = 0; p < sizet; p++)
	{
		for (long long k = 0; k < sizez; k++)
		{
			long long k1 = bz + k;
			for (long long j = 0; j < sizey; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i < hsize; i++)
				{
					long long i1 = bx + i;
				
					long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, hsize + i1, j1, k1, p);
					
					float Re = data[daddr_l].Re;
					float Img = data[daddr_l].Img;

					data[daddr_l].Re = data[daddr_r].Re; 
					data[daddr_l].Img = data[daddr_r].Img;
					data[daddr_r].Re = Re;
					data[daddr_r].Img = Img;

				}
			}
		}
	}
}

void cMagnetization::DoShiftedFormXParallel()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * sizet + 200;

	long long size = sizex;
	long long hsize = size/2;
	if (sizez > 1)
	{

		//parallel_for(long long(0), sizez, [&](long long k)
#pragma omp parallel for
		for (long long k = 0; k < sizez; k++)
		{
			long long k1 = bz + k;
			for (long long p = 0; p < sizet; p++)
			{
				for (long long j = 0; j < sizey; j++)
				{
					long long j1 = by + j;
					for (long long i = 0; i < hsize; i++)
					{
						long long i1 = bx + i;
				
						long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, hsize + i1, j1, k1, p);
					
						float Re = data[daddr_l].Re;
						float Img = data[daddr_l].Img;

						data[daddr_l].Re = data[daddr_r].Re; 
						data[daddr_l].Img = data[daddr_r].Img;
						data[daddr_r].Re = Re;
						data[daddr_r].Img = Img;

					}
				}
			}
		}//);
	}
	else
	{
		//parallel_for(long long(0), sizey, [&](long long j)
#pragma omp parallel for
		for (long long j = 0; j < sizey; j++)
		{
			long long j1 = by + j;
			for (long long p = 0; p < sizet; p++)
			{
				for (long long k = 0; k < sizez; k++)
				{
					long long k1 = bz + k;
				
					for (long long i = 0; i < hsize; i++)
					{
						long long i1 = bx + i;
				
						long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, hsize + i1, j1, k1, p);
					
						float Re = data[daddr_l].Re;
						float Img = data[daddr_l].Img;

						data[daddr_l].Re = data[daddr_r].Re; 
						data[daddr_l].Img = data[daddr_r].Img;
						data[daddr_r].Re = Re;
						data[daddr_r].Img = Img;

					}
				}
			}
		}//);
	}
}


void cMagnetization::DoShiftedFormY()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * sizet + 200;

	long long size = sizey;
	long long hsize = size/2;

	for (long long p = 0; p < sizet; p++)
	{
		for (long long k = 0; k < sizez; k++)
		{
			long long k1 = bz + k;
			for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					for (long long j = 0; j < hsize; j++)
					{
						long long j1 = by + j;

						long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, hsize + j1, k1, p);
					
						float Re = data[daddr_l].Re;
						float Img = data[daddr_l].Img;

						data[daddr_l].Re = data[daddr_r].Re; 
						data[daddr_l].Img = data[daddr_r].Img;
						data[daddr_r].Re = Re;
						data[daddr_r].Img = Img;

				}
			}
		}
	}
}

void cMagnetization::DoShiftedFormYParallel()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * sizet + 200;

	long long size = sizey;
	long long hsize = size/2;
	if (sizez > 1)
	{
			//parallel_for(long long(0), sizez, [&](long long k)
#pragma omp parallel for
			for (long long k = 0; k < sizez; k++)
			{
			long long k1 = bz + k;
				for (long long p = 0; p < sizet; p++)
				{		
				for (long long i = 0; i < sizex; i++)
					{
						long long i1 = bx + i;
						for (long long j = 0; j < hsize; j++)
						{
							long long j1 = by + j;

							long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
							long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, hsize + j1, k1, p);
					
							float Re = data[daddr_l].Re;
							float Img = data[daddr_l].Img;

							data[daddr_l].Re = data[daddr_r].Re; 
							data[daddr_l].Img = data[daddr_r].Img;
							data[daddr_r].Re = Re;
							data[daddr_r].Img = Img;

					}
				}
			}
		}//);
	}
	else
	{
		//parallel_for(long long(0), sizet, [&](long long p)
#pragma omp parallel for
		for (long long p = 0; p < sizet; p++)
		{	
			for (long long k = 0; k < sizez; k++)
			{
				long long k1 = bz + k;				
				for (long long i = 0; i < sizex; i++)
					{
						long long i1 = bx + i;
						for (long long j = 0; j < hsize; j++)
						{
							long long j1 = by + j;

							long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
							long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, hsize + j1, k1, p);
					
							float Re = data[daddr_l].Re;
							float Img = data[daddr_l].Img;

							data[daddr_l].Re = data[daddr_r].Re; 
							data[daddr_l].Img = data[daddr_r].Img;
							data[daddr_r].Re = Re;
							data[daddr_r].Img = Img;

					}
				}
			}
		}//);
	}
}
void cMagnetization::DoShiftedFormZ()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * sizet + 200;

	long long size = sizez;
	long long hsize = size/2;
	for (long long p = 0; p < sizet; p++)
	{
		for (long long j = 0; j < sizey; j++)
		{
			long long j1 = by + j;	
			for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					for (long long k = 0; k < hsize; k++)
					{
						long long k1 = bz + k;

						long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, hsize + k1, p);
					
						float Re = data[daddr_l].Re;
						float Img = data[daddr_l].Img;

						data[daddr_l].Re = data[daddr_r].Re; 
						data[daddr_l].Img = data[daddr_r].Img;
						data[daddr_r].Re = Re;
						data[daddr_r].Img = Img;
				}
			}
		}
	}
}

void cMagnetization::DoShiftedFormZParallel()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	int error = 0;
	long long commsize = 5 * sizet + 200;

	long long size = sizez;
	long long hsize = size/2;
	//parallel_for(long long(0), sizey, [&](long long j)
#pragma omp parallel for
	for (long long j = 0; j < sizey; j++)
	{
		long long j1 = by + j;
		for (long long p = 0; p < sizet; p++)
		{	
			for (long long i = 0; i < sizex; i++)
				{
					long long i1 = bx + i;
					for (long long k = 0; k < hsize; k++)
					{
						long long k1 = bz + k;

						long long daddr_l = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
						long long daddr_r = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, hsize + k1, p);
					
						float Re = data[daddr_l].Re;
						float Img = data[daddr_l].Img;

						data[daddr_l].Re = data[daddr_r].Re; 
						data[daddr_l].Img = data[daddr_r].Img;
						data[daddr_r].Re = Re;
						data[daddr_r].Img = Img;
				}
			}
		}
	}//);
}



void cMagnetization::Get4DFFT()
{
	long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;

	/*DoFFTTParallel();

	if (sizex != 1) DoFFTXParallel();
	if (sizey != 1) DoFFTYParallel();
	if (sizez != 1) DoFFTZParallel();*/

	DoFFTTParallel();

	if (sizex != 1) DoFFTX();//Parallel();
	if (sizey != 1) DoFFTY();//Parallel();
	if (sizez != 1) DoFFTZ();//Parallel();


	DoShiftedFormT();
	if (sizex != 1) DoShiftedFormX();
	if (sizey != 1) DoShiftedFormY();
	if (sizez != 1) DoShiftedFormZ();
}

void cMagnetization::Get4DFFTVolumeSlice(long long isAvgX, long long isAvgY, long long isAvgZ, long long AvgMX, long long AvgMY, long long AvgMZ, long long coordx, long long coordy, long long coordz)
{
	long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	m_isXavg = 0;
	m_isYavg = 0;
	m_isZavg = 0;
//**********Averaging in real space if required*****************
	if (AvgMX == 0 && isAvgX == 1) Do1DAveragingInplaceParallel(0);
	if (AvgMY == 0 && isAvgY == 1) Do1DAveragingInplaceParallel(1);
	if (AvgMZ == 0 && isAvgZ == 1) Do1DAveragingInplaceParallel(2);
//**************************************************************

//***********************4D FFT*********************************
	if (m_IsKDomain == 0 && m_IsFreqDomain == 0)// && (isAvgX != 0 || isAvgY !=0 || isAvgZ !=0))
	{
		DoFFTTParallel();
		printf("FFTT Done.");
		Do3DFFTParallel();
		DoShiftedFormTParallel();
		if (sizex != 1) DoShiftedFormXParallel();
		if (sizey != 1) DoShiftedFormYParallel();
		if (sizez != 1) DoShiftedFormZParallel();
		m_IsFreqDomain = 1;
		m_IsKDomain = 1;
		// X
		//***************************************************************
		if (AvgMX == 1 || AvgMY == 1 || AvgMZ == 1) DoAmpPhsFromParallel();
		//**********Averaging in reciprocal space if required************
		if (AvgMX == 1 && isAvgX == 1) Do1DAveragingInplaceParallel(0);
		if (AvgMY == 1 && isAvgY == 1) Do1DAveragingInplaceParallel(1);
		if (AvgMZ == 1 && isAvgZ == 1) Do1DAveragingInplaceParallel(2);
		//***************************************************************
	}
	Get2Dfrom4DVolume(isAvgX, isAvgY, isAvgZ, coordx, coordy, coordz);
}

void cMagnetization::Get2Dfrom4DVolume(long long isavgx, long long isavgy, long long isavgz, long long coordx, long long coordy, long long coordz)
{
	long long adeg = isavgx + isavgy + isavgz;
	long long faxis = 0;
	long long aaxis = 0;
	long long coordA = 0;
	long long coordB = 0;
	long long guess = 0;

	switch(adeg)
	{
	case 0:
		// DATA ARE NOT AVERAGED AT ANY POINT	
		// Guess the fixed axis
		if (coordx == -1) 
		{
			// X
			faxis = 0;
			coordA = coordy;
			coordB = coordz;
		}
		if (coordy == -1) 
		{
			// Y
			faxis = 1;
			coordA = coordx;
			coordB = coordz;
		}
		if (coordz == -1)
		{
			// Z
			faxis = 2;
			coordA = coordx;
			coordB = coordy;
		}
		Get2Dfrom4DNAvg(faxis, coordA, coordB);
		break;
	case 1:
		// ONLY ONE DIRECTION IS AVERAGED
		// GUESS DIRECTION
		if (coordx == -1) 
		{
			// X
			faxis = 0;
		}
		if (coordy == -1) 
		{
			// Y
			faxis = 1;
		}
		if (coordz == -1)
		{
			// Z
			faxis = 2;
		}

		if (isavgx == 1) 
		{
			// X
			aaxis = 0;
			switch(faxis)
			{
			case 0:
				// X - averaged, X - fixed causing error!!!!!!!
				coordA = coordx;
				break;
			case 1:
				// X - averaged, Y - fixed: Z slice
				coordA = coordz;
				break;
			case 2:
				// X - averaged, Z - fixed: Y slice
				coordA = coordy;
				break;
			}
		}
		if (isavgy == 1) 
		{
			// Y
			aaxis = 1;
			switch(faxis)
			{
			case 0:
				// Y - averaged, X fixed: Z slice
				coordA = coordz;
				break;
			case 1:
				// Y - averaged, Y fixed: ERROR
				coordA = coordy;
				break;
			case 2:
				// Y - averaged, Z fixed: X slice
				coordA = coordx;
				break;
			}
		}
		if (isavgz == 1)
		{
			// Z
			aaxis = 2;
			switch(faxis)
			{
			case 0:
				// Z - averaged, X fixed: Y slice
				coordA = coordy;
				break;
			case 1:
				// Z - averaged, Y fixed: X slice
				coordA = coordx;
				break;
			case 2:
				// Z - averaged, Z fixed: ERROR
				coordA = coordz;
				break;
			}
		}
		Get2Dfrom4DSAvg(faxis, aaxis, coordA);	
		break;
	case 2:
		// TWO DIRECTIONS ARE AVERAGED
		// GUESSING fixed axis!
		faxis = 0;
		guess = isavgx + 2 * isavgy + 4 * isavgz;
		switch (guess)
		{
		case 6:
			// X
			faxis = 0;
			break;
		case 5:
			// Y
			faxis = 1;
			break;
		case 3:
			// Z
			faxis = 2;
			break;
		}
		Get2Dfrom4DDAvg(faxis);
		break;
	case 3:
		// ALL THREE DIRECTIONS ARE AVERAGED
		Get2Dfrom4DTAvg();
		break;
	}
}

void cMagnetization::Get2Dfrom4DNAvg(long long fixedaxis, long long coordA, long long coordB)
{
	long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;
	long long j1 = 0;
	long long i1 = 0;
	long long k1 = 0;

	switch(fixedaxis)
	{
	case 0:
		// X is fixed
		AllocateAvgFFTBuffer(sizex, 1, 1, sizet);
		j1 = coordA + by;
		k1 = coordB + bz;
		for (long long p = 0; p < sizet; p++)
		{
			for (long long i = 0; i < sizex; i++)
			{
				i1 = bx + i;
				long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
				long long naddr = p_addr_xy_v1(sizex, i, p);
				avgdata_fft[naddr].Re = data[daddr].Re;
				avgdata_fft[naddr].Img = data[daddr].Img;
			}
		}
		break;
	case 1:
		// Y is fixed
		AllocateAvgFFTBuffer(sizey, 1, 1, sizet);
		i1 = coordA + bx;
		k1 = coordB + bz;
		for (long long p = 0; p < sizet; p++)
		{
			for (long long j = 0; j < sizey; j++)
			{
				j1 = by + j;
				long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
				long long naddr = p_addr_xy_v1(sizey, j, p);
				avgdata_fft[naddr].Re = data[daddr].Re;
				avgdata_fft[naddr].Img = data[daddr].Img;
			}
		}
		break;
	case 2:
		// Y is fixed
		AllocateAvgFFTBuffer(sizez, 1, 1, sizet);
		i1 = coordA + bx;
		j1 = coordB + by;
		for (long long p = 0; p < sizet; p++)
		{
			for (long long k = 0; k < sizez; k++)
			{
				k1 = bz + k;
				long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
				long long naddr = p_addr_xy_v1(sizez, k, p);
				avgdata_fft[naddr].Re = data[daddr].Re;
				avgdata_fft[naddr].Img = data[daddr].Img;
			}
		}
		break;
	}
}
void cMagnetization::Get2Dfrom4DSAvg(long long fixedaxis, long long avg, long long coordA)
{
	long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;
	long long i1 = 0;
	long long j1 = 0;
	long long k1 = 0;

	switch(avg)
	{
	case 0:
		// X is averaged so free is Y and Z;
		i1 = bx;
		k1 = coordA + bz;
		j1 = coordA + by;
		break;
	case 1:
		// Y is averaged so free is X and Z;
		j1 = by;
		k1 = coordA + bz;
		i1 = coordA + bx;
		break;
	case 2:
		// Z is averaged so free is X and Y
		k1 = bz;
		j1 = coordA + by;
		i1 = coordA + bx;
		break;
	}
	switch(fixedaxis)
	{
	case 0:
		// X is fixed
		AllocateAvgFFTBuffer(sizex, 1, 1, sizet);
		for (long long p = 0; p < sizet; p++)
		{
			for (long long i = 0; i < sizex; i++)
			{
				i1 = bx + i;
				long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
				long long naddr = p_addr_xy_v1(sizex, i, p);
				avgdata_fft[naddr].Re = data[daddr].Re;
				avgdata_fft[naddr].Img = data[daddr].Img;
			}
		}
		break;
	case 1:
		// Y is fixed
		AllocateAvgFFTBuffer(sizey, 1, 1, sizet);
		for (long long p = 0; p < sizet; p++)
		{
			for (long long j = 0; j < sizey; j++)
			{
				j1 = by + j;
				long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
				long long naddr = p_addr_xy_v1(sizey, j, p);
				avgdata_fft[naddr].Re = data[daddr].Re;
				avgdata_fft[naddr].Img = data[daddr].Img;
			}
		}
		break;
	case 2:
		// Y is fixed
		AllocateAvgFFTBuffer(sizez, 1, 1, sizet);
		for (long long p = 0; p < sizet; p++)
		{
			for (long long k = 0; k < sizez; k++)
			{
				k1 = bz + k;
				long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
				long long naddr = p_addr_xy_v1(sizez, k, p);
				avgdata_fft[naddr].Re = data[daddr].Re;
				avgdata_fft[naddr].Img = data[daddr].Img;
			}
		}
		break;
	}
}
void cMagnetization::Get2Dfrom4DDAvg(long long fixedaxis)
{
	long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	long long i1 = bx;
	long long j1 = by;
	long long k1 = bz;

	switch(fixedaxis)
	{
	case 0:
		// X is fixed
		AllocateAvgFFTBuffer(sizex, 1, 1, sizet);
		for (long long p = 0; p < sizet; p++)
		{
			for (long long i = 0; i < sizex; i++)
			{
				i1 = bx + i;
				long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
				long long naddr = p_addr_xy_v1(sizex, i, p);
				avgdata_fft[naddr].Re = data[daddr].Re;
				avgdata_fft[naddr].Img = data[daddr].Img;
			}
		}
		break;
	case 1:
		// Y is fixed
		AllocateAvgFFTBuffer(sizey, 1, 1, sizet);
		for (long long p = 0; p < sizet; p++)
		{
			for (long long j = 0; j < sizey; j++)
			{
				j1 = by + j;
				long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
				long long naddr = p_addr_xy_v1(sizey, j, p);
				avgdata_fft[naddr].Re = data[daddr].Re;
				avgdata_fft[naddr].Img = data[daddr].Img;
			}
		}
		break;
	case 2:
		// Y is fixed
		AllocateAvgFFTBuffer(sizez, 1, 1, sizet);
		for (long long p = 0; p < sizet; p++)
		{
			for (long long k = 0; k < sizez; k++)
			{
				k1 = bz + k;
				long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
				long long naddr = p_addr_xy_v1(sizez, k, p);
				avgdata_fft[naddr].Re = data[daddr].Re;
				avgdata_fft[naddr].Img = data[daddr].Img;
			}
		}
		break;
	}

}
void cMagnetization::Get2Dfrom4DTAvg()
{
	long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	long long i1 = bx;
	long long j1 = by;
	long long k1 = bz;

	AllocateAvgFFTBuffer(1, 1, 1, sizet);

	for (long long p = 0; p < sizet; p++)
	{
		long long daddr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
		avgdata_fft[p].Re = data[daddr].Re;
		avgdata_fft[p].Img = data[daddr].Img;

	}
}

void cMagnetization::DoAmpPhsFrom()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	for (long long p = 0; p < sizet; p++)
	{
		for (long long k = 0; k < sizez; k++)
		{
			long long k1 = k + bz;
			for (long long j = 0; j < sizey; j++)
			{
				long long j1 = j + by;
				for (long long i = 0; i < sizex; i++)
				{
					long long i1 = i + bx;
					long long addr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					float Re = data[addr].Re;
					float Img = data[addr].Img;
					float Amp = sqrtf(Re * Re + Img * Img);
					float Phz = atan2f(Img, Re);
					data[addr].Re = Amp;
					data[addr].Img = Phz;
				}
			}
		}
	}
}
void cMagnetization::DoAmpPhsFromParallel()
{
	long long sizex, sizey, sizez;
	if (m_isXavg == 1) sizex = 1;
	else sizex = cProbe::sizeX;

	if (m_isYavg == 1) sizey = 1;
	else sizey = cProbe::sizeY;

	if (m_isZavg == 1) sizez = 1;
	else sizez = cProbe::sizeZ;

	/*long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;*/
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;
	//parallel_for(long long(0), sizey, [&](long long j)
#pragma omp parallel for
	for (long long j = 0; j < sizey; j++)
	{
		long long j1 = j + by;

		for (long long p = 0; p < sizet; p++)
		{
			for (long long k = 0; k < sizez; k++)
			{
				long long k1 = k + bz;
			
				for (long long i = 0; i < sizex; i++)
				{
					long long i1 = i + bx;
					long long addr = p_addr_xyzt_v1(dsizex, dsizey, dsizez, i1, j1, k1, p);
					float Re = data[addr].Re;
					float Img = data[addr].Img;
					float Amp = sqrtf(Re * Re + Img * Img);
					float Phz = atan2f(Img, Re);
					data[addr].Re = Amp;
					data[addr].Img = Phz;
				}
			}
		}
	}//);
}

void cMagnetization::DoFF2A()
{
	//Apply 4D FFT first
	long long sizex = cProbe::sizeX;
	long long sizey = cProbe::sizeY;
	long long sizez = cProbe::sizeZ;
	long long sizet = s_params.m_NumberOfTimeSteps;
	long long bx = cProbe::X0;
	long long by = cProbe::Y0;
	long long bz = cProbe::Z0;

	long long dsizex = s_params.m_SizeX;
	long long dsizey = s_params.m_SizeY;
	long long dsizez = s_params.m_SizeZ;

	m_isXavg = 0;
	m_isYavg = 0;
	m_isZavg = 0;

//***********************4D FFT*********************************
	if (m_IsKDomain == 0 && m_IsFreqDomain == 0)// && (isAvgX != 0 || isAvgY !=0 || isAvgZ !=0))
	{
		DoFFTTParallel();
		printf("FFTT Done.");
		Do3DFFTParallel();
		DoShiftedFormTParallel();
		if (sizex != 1) DoShiftedFormXParallel();
		if (sizey != 1) DoShiftedFormYParallel();
		if (sizez != 1) DoShiftedFormZParallel();
		m_IsFreqDomain = 1;
		m_IsKDomain = 1;
		//DoAmpPhsFromParallel();
	}
	Do3DAveragingBWCMPXParallel(0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
	DoShiftedFormSpectrumParallel();

}


void cMagnetization::DoShiftedFormSpectrumParallel()
{

	long long sx = m_asizeX;
	long long sy = m_asizeY;
	long long sz = m_asizeZ;

	long long hx = sx / 2;
	long long hy = sy / 2;
	long long hz = sz / 2;

	for (int i = 0; i < sx; i++)
	{
		for (int j=0; j < sy; j++)
		{
			for (int k=0; k < hz; k++)
			{
				long long addr_l = p_addr_xyz_v1(sx, sy, i, j, k);
				long long addr_r = p_addr_xyz_v1(sx, sy, i, j, k + hz);

				float tRe = avgdata[addr_l].Re;
				float tImg = avgdata[addr_l].Img;

				avgdata[addr_l].Re = avgdata[addr_r].Re;
				avgdata[addr_l].Img = avgdata[addr_r].Img;

				avgdata[addr_r].Re = tRe;
				avgdata[addr_r].Img = tImg;		
			}
		}
	}
}

void cMagnetization::GetMultipoleCoeff(long long t, long long order, double** Q, long long** size)
{
	long long tenssize = (long long)pow(3.0, (double)order);
	*Q = (double*)malloc(tenssize*sizeof(double));


	for (int i = 0; i < tenssize; i++)
	{
		*(*Q + i) = 0.0;
	}

	double PI = 4.0F * atanf(1.0F);
	double PIo2 = PI / 2.0;

	long long sx = s_params.m_SizeX;
	long long sy = s_params.m_SizeY;
	long long sz = s_params.m_SizeZ;

	long long i0 = cProbe::X0;
	long long j0 = cProbe::Y0;
	long long k0 = cProbe::Z0;

	long long psx = cProbe::sizeX;
	long long psy = cProbe::sizeY;
	long long psz = cProbe::sizeZ;
	double q = 0.0;

	// have to guess the relative phase prior the the coefficients calculation

	double mamp = 0.0;
	double mphz = 0.0;
	double value;

	/*for (long long k = k0; k < psz; k++)
	{
		for (long long j = j0; j < psy; j++)
		{
			for (long long i = i0; i < psx; i++)
			{
				double x = i * s_params.m_CellSizeX;
				double y = j * s_params.m_CellSizeY;
				double z = k * s_params.m_CellSizeZ;

				long long addr = p_addr_xyzt_v1(sx, sy, sz, i, j, k, t);
				
				float Re = data[addr].Re;
				float Img = data[addr].Img;

				double Amp = sqrt(Re * Re + Img * Img);
				double Phz = atan2(Img, Re);
				
				if (Amp > mamp) 
				{
					mamp = Amp;
					mphz = Phz;
				}

			}
		}
	}*/

	double pshift = 0.0; //PIo2 - mphz;


	switch (order)
	{
	case 0LL:
		// monopole
		for (long long k = k0; k < psz; k++)
		{
			for (long long j = j0; j < psy; j++)
			{
				for (long long i = i0; i < psx; i++)
				{
					double x = i * s_params.m_CellSizeX;
					double y = j * s_params.m_CellSizeY;
					double z = k * s_params.m_CellSizeZ;

					long long addr = p_addr_xyzt_v1(sx, sy, sz, i, j, k, t);
				
					float Re = data[addr].Re;
					float Img = data[addr].Img;

					double Amp = sqrt(Re * Re + Img * Img);
					double Phz = atan2(Img, Re);

					double chg = Amp * sin(pshift + Phz);

					*(*Q + 0) += chg;
				}
			}
		}
		break;
	case 1LL:
		// dipole
		for (long long k = k0; k < psz; k++)
		{
			for (long long j = j0; j < psy; j++)
			{
				for (long long i = i0; i < psx; i++)
				{
					double x = i * s_params.m_CellSizeX;
					double y = j * s_params.m_CellSizeY;
					double z = k * s_params.m_CellSizeZ;

					long long addr = p_addr_xyzt_v1(sx, sy, sz, i, j, k, t);
				
					float Re = data[addr].Re;
					float Img = data[addr].Img;

					double Amp = sqrt(Re * Re + Img * Img);
					double Phz = atan2(Img, Re);

					double chg = Amp * sin(pshift + Phz);

					*(*Q + 0) += chg * x;
					*(*Q + 1) += chg * y;
					*(*Q + 2) += chg * z;

				}
			}
		}
		break;
	case 2LL:
		// quadrupole
		for (long long k = k0; k < psz; k++)
		{
			for (long long j = j0; j < psy; j++)
			{
				for (long long i = i0; i < psx; i++)
				{
					double x = i * s_params.m_CellSizeX;
					double y = j * s_params.m_CellSizeY;
					double z = k * s_params.m_CellSizeZ;

					double r2 = (x * x + y * y + z * z);

					long long addr = p_addr_xyzt_v1(sx, sy, sz, i, j, k, t);
				
					float Re = data[addr].Re;
					float Img = data[addr].Img;

					double Amp = sqrt(Re * Re + Img * Img);
					double Phz = atan2(Img, Re);

					double chg = Amp * sin(pshift + Phz);

					//xx
					*(*Q + 0) += chg * (3.0 * x * x - r2);
					//xy
					*(*Q + 1) += chg * (3.0 * x * y);
					//xz
					*(*Q + 2) += chg * (3.0 * x * z);

					//yx
					*(*Q + 3) += chg * (3.0 * y * x);
					//yy
					*(*Q + 4) += chg * (3.0 * y * y - r2);
					//yz
					*(*Q + 5) += chg * (3.0 * y * z);

					//zx
					*(*Q + 6) += chg * (3.0 * z * x);
					//yy
					*(*Q + 7) += chg * (3.0 * z * y);
					//yz
					*(*Q + 8) += chg * (3.0 * z * z - r2);			
				}
			}
		}
		break;
	}
	(*size[0]) = tenssize;
}

void cMagnetization::GetOrigin(long long t, double** r)
{

	long long sx = s_params.m_SizeX;
	long long sy = s_params.m_SizeY;
	long long sz = s_params.m_SizeZ;

	long long i0 = cProbe::X0;
	long long j0 = cProbe::Y0;
	long long k0 = cProbe::Z0;

	long long psx = cProbe::sizeX;
	long long psy = cProbe::sizeY;
	long long psz = cProbe::sizeZ;

	double q = 0.0;
	double qx = 0.0;
	double qy = 0.0;
	double qz = 0.0;
	for (long long k = k0; k < psz; k++)
	{
		for (long long j = 0; j < psy; j++)
		{
			for (long long i = 0; i < psx; i++)
			{
				double x = i * s_params.m_CellSizeX;
				double y = j * s_params.m_CellSizeY;
				double z = k * s_params.m_CellSizeZ;

				long long addr = p_addr_xyzt_v1(sx, sy, sz, i, j, k, t);
				
				float Re = data[addr].Re;
				float Img = data[addr].Img;

				double chg = sqrt(Re * Re + Img * Img) * sin(atan2(Img, Re));

			}
		}
	}

}

void cMagnetization::Get3DModeWaveNumber()
{

	// Calculate 3D DFT of the mode
	long long sizex = m_lsizeX;
	long long sizey = m_lsizeY;
	long long sizez = m_lsizeZ;

	double* dax = (double*)new double[sizex];
	double* day = (double*)new double[sizey];
	double* daz = (double*)new double[sizez];

	long long commsize = sizex * sizey * sizez + 4 * (sizex + sizey + sizez) + 300;//L*M*N + 4*(L+M+N) + 300//5 * (sizex + sizey + sizez) + 150;
	// allocate one huge buffer for communication
	COMPLEX* comm = (COMPLEX*)new float[2 * commsize];
	int err = 0;
	cFFT::InitZFFT3Df(sizex, sizey, sizez, sizex, sizey, sizez, commsize, 1.0, (COMPLEX*)&layer_buff_3d[0].Re, (COMPLEX*)&comm[0].Re, NULL, &err);
	cFFT::ZFFT3Df(sizex, sizey, sizez, sizex, sizey, sizez, commsize, 1.0, (COMPLEX*)&layer_buff_3d[0].Re, (COMPLEX*)&comm[0].Re, NULL, &err);
	delete[] (float*)comm;

	// Brings to shifted form
	long long hsizex = sizex / 2;
	long long hsizey = sizey / 2;
	long long hsizez = sizez / 2;
	// X
	for (long long k = 0 ; k < sizez; k++)
	{
		for (long long j = 0; j < sizey; j++)
		{
			for (long long i = 0; i < hsizex; i++)
			{
				long long addr_l = p_addr_xyz_v1(sizex, sizey, i, j , k);
				long long addr_r = p_addr_xyz_v1(sizex, sizey, i + hsizex, j, k);

				float Re = layer_buff_3d[addr_l].Re;
				float Img = layer_buff_3d[addr_l].Img;
				
				layer_buff_3d[addr_l].Re = layer_buff_3d[addr_r].Re;
				layer_buff_3d[addr_l].Img = layer_buff_3d[addr_r].Img;

				layer_buff_3d[addr_r].Re = Re;
				layer_buff_3d[addr_r].Img = Img;
			}
		}
	}

	// Y
	for (long long k = 0 ; k < sizez; k++)
	{
		for (long long j = 0; j < hsizey; j++)
		{
			for (long long i = 0; i < sizex; i++)
			{
				long long addr_l = p_addr_xyz_v1(sizex, sizey, i, j , k);
				long long addr_r = p_addr_xyz_v1(sizex, sizey, i, j + hsizey, k);

				float Re = layer_buff_3d[addr_l].Re;
				float Img = layer_buff_3d[addr_l].Img;
				
				layer_buff_3d[addr_l].Re = layer_buff_3d[addr_r].Re;
				layer_buff_3d[addr_l].Img = layer_buff_3d[addr_r].Img;

				layer_buff_3d[addr_r].Re = Re;
				layer_buff_3d[addr_r].Img = Img;
			}
		}
	}
	// Z
	for (long long k = 0 ; k < hsizez; k++)
	{
		for (long long j = 0; j < sizey; j++)
		{
			for (long long i = 0; i < sizex; i++)
			{
				long long addr_l = p_addr_xyz_v1(sizex, sizey, i, j, k);
				long long addr_r = p_addr_xyz_v1(sizex, sizey, i, j, k + hsizez);

				float Re = layer_buff_3d[addr_l].Re;
				float Img = layer_buff_3d[addr_l].Img;
				
				layer_buff_3d[addr_l].Re = layer_buff_3d[addr_r].Re;
				layer_buff_3d[addr_l].Img = layer_buff_3d[addr_r].Img;

				layer_buff_3d[addr_r].Re = Re;
				layer_buff_3d[addr_r].Img = Img;
			}
		}
	}
// Now do averaging of the data
	
	double imul = 0.0;
	// X
	imul = 1.0 / ((double)sizey * (double)sizez);

	for (long long i = 0; i < sizex; i++)
	{
		double aAmp = 0.0;

		for (long long k = 0 ; k < sizez; k++)
		{
			for (long long j = 0; j < sizey; j++)
			{
				
				long long addr = p_addr_xyz_v1(sizex, sizey, i, j, k);
				
				double Re = layer_buff_3d[addr].Re;
				double Img = layer_buff_3d[addr].Img;

				aAmp += sqrt(Re * Re + Img * Img);

			}
		}
		dax[i] = aAmp * imul;
	}

	// Y
	imul = 1.0 / ((double)sizex * (double)sizez);
	for (long long j = 0; j < sizey; j++)
	{
		double aAmp = 0.0;
		for (long long k = 0 ; k < sizez; k++)
		{	
			for (long long i = 0; i < sizex; i++)
			{
				
				long long addr = p_addr_xyz_v1(sizex, sizey, i, j, k);
				
				double Re = layer_buff_3d[addr].Re;
				double Img = layer_buff_3d[addr].Img;

				aAmp += sqrt(Re * Re + Img * Img);

			}
		}
		day[j] = aAmp * imul;
	}
	// Z
	imul = 1.0 / ((double)sizex * (double)sizey);
	for (long long k = 0 ; k < sizez; k++)
	{
		double aAmp = 0.0;	
		for (long long j = 0; j < sizey; j++)
		{	
			for (long long i = 0; i < sizex; i++)
			{
				
				long long addr = p_addr_xyz_v1(sizex, sizey, i, j, k);
				
				double Re = layer_buff_3d[addr].Re;
				double Img = layer_buff_3d[addr].Img;

				aAmp += sqrt(Re * Re + Img * Img);

			}
		}
		daz[k] = aAmp * imul;
	}

	// Find the maxima
	// X 
	long long coord;
	double max;
	// X
	coord = 0;
	max = dax[coord];
	for (long long i = 1 ; i < sizex - 1; i++)
	{
		double maxt = dax[i];
		if (maxt >= max)
		{
			// check if it is a real peak		
			double maxp = dax[i - 1];
			double maxn = dax[i + 1];
			if (maxt > maxp && maxt > maxn)
			{
				if (i >= hsizex-1 && i <= hsizex + 1 && coord != 0)
				{
					double maxc = dax[i];
					if (max < PEAKREJ * maxc)
					{
						max = maxt;
						coord = i;	
					}

				}
				else
				{
					max = maxt;
					coord = i;		
				}
			}
		}
	}
	coord = coord - hsizex;
	double kx = (double)coord * s_params.m_ResInverseWavelengthX;
	double nx = 2.0 * kx * s_params.m_SizeX * s_params.m_CellSizeX;
	k3d[0] = kx;
	n3d[0] = nx;
	// Y
	coord = 0;
	max = day[coord];
	for (long long j = 1 ; j < sizey - 1; j++)
	{
		double maxt = day[j];
		if (maxt >= max)
		{
			// check if it is a real peak
			double maxp = day[j - 1];
			double maxn = day[j + 1];
			if (maxt > maxp && maxt > maxn)
			{
				if (j >= hsizey - 1 && j <= hsizey + 1 && coord != 0)
				{
					double maxc = day[j];
					if (max < PEAKREJ * maxc)
					{
						max = maxt;
						coord = j;
					}

				}
				else
				{
					max = maxt;
					coord = j;	
				}
			}
		}
	}
	coord = coord - hsizey;
	double ky = (double)coord * s_params.m_ResInverseWavelengthY;
	double ny = 2.0 * ky * s_params.m_SizeY * s_params.m_CellSizeY;
	k3d[1] = ky;
	n3d[1] = ny;
	// Z
	coord = 0;
	max = daz[coord];
	for (long long k = 1; k < sizez - 1; k++)
	{
		double maxt = daz[k];
		if (maxt >= max)
		{
			// check if it is a real peak
			double maxp = daz[k - 1];
			double maxn = daz[k + 1];
			if (maxt > maxp && maxt > maxn)
			{
				if (k >= hsizez - 1 && k <= hsizez + 1 && coord != 0)
				{
					double maxc = daz[k];
					if (max < PEAKREJ * maxc)
					{
						max = maxt;
						coord = k;
					}

				}
				else
				{
					max = maxt;
					coord = k;	
				}	
			}	
		}
	}
	coord = coord - hsizez;
	double kz = (double)coord * s_params.m_ResInverseWavelengthZ;
	double nz = 2.0 * kz * s_params.m_SizeZ * s_params.m_CellSizeZ;
	k3d[2] = kz;
	n3d[2] = nz;

	delete[] dax;
	delete[] day;
	delete[] daz;
}

#pragma managed