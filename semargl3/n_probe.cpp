#pragma unmanaged

#include "n_probe.h"
#include "memory.h"
#include "n_common_func.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long cProbe::ProbeType = 0;

long long cProbe::X0 = 0;
long long cProbe::Y0 = 0;
long long cProbe::Z0 = 0;

long long cProbe::X1 = 0;
long long cProbe::Y1 = 0;
long long cProbe::Z1 = 0;

double cProbe::X0_m = 0;
double cProbe::Y0_m = 0;
double cProbe::Z0_m = 0;

double cProbe::X1_m = 0;
double cProbe::Y1_m = 0;
double cProbe::Z1_m = 0;

long long cProbe::sizeX = 0;
double cProbe::sizeX_m = 0.0;
long long cProbe::sizeY =0;
double cProbe::sizeY_m =0.0;
long long cProbe::sizeZ = 0;
double cProbe::sizeZ_m = 0.0;

float* cProbe::probe;
long long cProbe::isCreated = 0;

double cProbe::m_multResInverseWavelengthX = 0.0;
double cProbe::m_multResInverseWavelengthY = 0.0;
double cProbe::m_multResInverseWavelengthZ = 0.0;

double cProbe::m_skindepthX = 0.0;
double cProbe::m_skindepthY = 0.0;
double cProbe::m_skindepthZ = 0.0;

void cProbe::Reset()
{
	X0 = 0;
	Y0 = 0;
	Z0 = 0;

	X1 = 0;
	Y1 = 0;
	Z1 = 0;
	

	X0_m = 0.0;
	Y0_m = 0.0;
	Z0_m = 0.0;

	X1_m = 0.0;
	Y1_m = 0.0;
	Z1_m = 0.0;

	sizeX = 0;
	sizeY = 0;
	sizeZ = 0;

	sizeX_m = 0.0;
	sizeY_m = 0.0;
	sizeZ_m = 0.0;

	m_skindepthX = 0.0;
	m_skindepthY = 0.0;
	m_skindepthZ = 0.0;

	isCreated = 0;
	if (probe != NULL) delete[] probe;

}


void cProbe::Create(long long fsizeX, long long fsizeY, long long fsizeZ, double csx, double csy, double csz)
{
	delete[] probe;

	if (sizeX == 0 && sizeY == 0 && sizeZ == 0)
	{
		isCreated = 0;
		return;

	}
	
	long long size = sizeX * sizeY * sizeZ;
	probe = new float[size];
	for (long long k = 0; k < sizeZ;k++)
	{
		for (long long j=0; j < sizeY;j++)
		{
			for (long long i=0; i < sizeX; i++)
			{
				long long adr = p_addr_xyz_v1(sizeX, sizeY, i, j, k);
				double x = i * csx;
				double y = j * csy;
				double z = k * csz;
				double val = 1.0;
				val = (m_skindepthX > 0.0)?val*exp(-x/m_skindepthX):val;
				val = (m_skindepthY > 0.0)?val*exp(-y/m_skindepthY):val;
				val = (m_skindepthZ > 0.0)?val*exp(-z/m_skindepthZ):val;

				probe[adr]=val;
			}
		}
	}
	m_multResInverseWavelengthX = fsizeX/ sizeX;
	m_multResInverseWavelengthY = fsizeY/ sizeY;
	m_multResInverseWavelengthZ = fsizeZ/ sizeZ;


	isCreated = 1;

}

#pragma managed