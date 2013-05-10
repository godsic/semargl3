#pragma unmanaged

#include "n_vfft.h"
#include "n_common_func.h"
#include <math.h>

float* cFFT::window;
long long cFFT::m_winsize = 0;
long long cFFT::m_IsWindowGenerated = 0;
long long cFFT::m_IsRectWindow = 0;

void cFFT::GenerateWindow(long long type, long long size, double alpha)
{
	m_winsize = size;
	window = new float[m_winsize];
	
	switch(type)
	{
	case 0:
		// RECT WINDOW
		GenRectWin(&window[0], m_winsize);
		m_IsRectWindow = 1;
		m_IsWindowGenerated = 1;
		break;
	case 1:
		// WELCH WINDOW
		GenWelchWin(&window[0], m_winsize);
		m_IsRectWindow = 0;
		m_IsWindowGenerated = 1;
		break;
	case 2:
		// KEISER WINDOW
		GenKieserWin(&window[0], m_winsize, alpha);
		m_IsRectWindow = 1;
		m_IsWindowGenerated = 1;
		break;
	case 3:
		// Hamming WINDOW
		GenHammWin(&window[0], m_winsize);
		m_IsRectWindow = 0;
		m_IsWindowGenerated = 1;

		break;
	}
	return;
}

void cFFT::GenWelchWin(float* win, long long size)
{
	double Koeff = size / 2.0;

	for (long long i = 0; i < size; i++)
	{
		double arg = (i - Koeff) / Koeff;
		double welch_i = 1.0 - (arg * arg);
		win[i] = (float)welch_i;
	}
}
void cFFT::GenKieserWin(float* win, long long size, double alpha)
{
	double Koeff = 2.0 / size;
	double Bessel0_Alpha = 1.0 / besselI0(alpha);

	for (long long i = 0; i < size; i++)
	{
		double Arg = (i * Koeff) - 1;
		Arg *= Arg;

		double BesselArg = alpha * (sqrt(1 - Arg));
		double KeiserFuncion_i = besselI0(BesselArg) * Bessel0_Alpha;
		win[i] = (float)KeiserFuncion_i;

	}
}



void cFFT::GenRectWin(float *win, long long size)
{
	for (long long i = 0; i < size; i++) win[i] = 1.0;
}

void cFFT::GenHammWin(float *win, long long size)
{
	long long N = size - 1;
	double DPI = 2.0 * 4.0 * atan(1.0);
	for (long long i=0;i<size;i++)
	{
		double val = 0.54 - 0.46 * cos(DPI*i/N);
		win[i] = (float)val;
	}
}


void cFFT::ApplyWindow1D(COMPLEX *data)
{
	for (long long p = 0; p < m_winsize; p++)
	{
		const float val = window[p];
		data[p].Re = data[p].Re * val;
		data[p].Img = data[p].Img * val;
	}
}

void cFFT::ApplyWindow2D(COMPLEX *data, long long size_x)
{
	for (long long p = 0; p < m_winsize; p++)
	{
		const float val = window[p];
		for (long long i = 0; i < size_x; i++)
		{
			long long addr = p_addr_xy_v1(size_x, i, p);
			data[addr].Re = data[addr].Re * val;
			data[addr].Img = data[addr].Img * val;
		}
	}
}

void cFFT::ApplyWindow3D(COMPLEX *data, long long size_x, long long size_y)
{
	for (long long p = 0; p < m_winsize; p++)
	{
		const float val = window[p];
		for (long long j = 0; j < size_y; j++)
		{
			for (long long i = 0; i < size_x; i++)
			{
				long long addr = p_addr_xyz_v1(size_x, size_y, i, j, p);
				data[addr].Re = data[addr].Re * val;
				data[addr].Img = data[addr].Img * val;
			}
		}
	}
}

void cFFT::ApplyWindow4D(COMPLEX *data, long long bx, long long by, long long bz, long long wsize_x, long long wsize_y, long long wsize_z, long long size_x, long long size_y, long long size_z)
{
	for (long long p = 0; p < m_winsize; p++)
	{
		const float val = window[p];
		for (long long k = 0; k < wsize_z; k++)
		{
			long long k1 = bz + k;
			for (long long j = 0; j < wsize_y; j++)
			{
				long long j1 = by + j;
				for (long long i = 0; i < wsize_x; i++)
				{
					long long i1 = bx + i;
					long long addr = p_addr_xyzt_v1(size_x, size_y, size_z, i1, j1, k1, p);
					data[addr].Re = data[addr].Re * val;
				    data[addr].Img = data[addr].Img * val;
				}
			}
		}
	}
}








void cFFT::InitZFFT1D(long long size, COMPLEX *data, COMPLEX *comm, int* info)
{
	cfft1d(100, (int)size, (complex*)&data[0].Re, (complex*)&comm[0].Re, info);
	return;
}
void cFFT::InitZFFT1DSimple(long long size, COMPLEX *data, COMPLEX *comm, int* info)
{
	cfft1d(0, (int)size, (complex*)&data[0].Re, (complex*)&comm[0].Re, info);
	return;
}
void cFFT::ZFFT1D(long long size, COMPLEX *data, COMPLEX *comm, int* info)
{
	cfft1d(-1, (int)size, (complex*)&data[0].Re, (complex*)&comm[0].Re, info);
	return;

}

void cFFT::ZFFT1DSimple(long long size, COMPLEX* data, COMPLEX* comm, int* info)
{
	cfft1d(-2, (int)size, (complex*)&data[0].Re, (complex*)&comm[0].Re, info);
}

void cFFT::InitZFFT2D(long long size_x, long long size_y, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info)
{
	//long long ltrans = 1;
	//long long inplace = 0;
	//cfft2dx(100, 1.0, ltrans, inplace,
	//	size_y, size_x, (complex*)&data[0].Re, 
	//    1, size_y, (complex*)&out[0].Re, 
	//	1, size_x, (complex*)&comm[0].Re, info);
	//return;
}
void cFFT::ZFFT2D(long long size_x, long long size_y, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info)
{
	long long ltrans = 0;
	long long inplace = 0;
	//cfft2dx(-1, 1.0, ltrans, inplace,
	//	size_y, size_x, (complex*)&data[0].Re, 
	//	1, size_y, (complex*)&out[0].Re, 
	//	1, size_x, (complex*)&comm[0].Re, info);
	//return;
	cfft2d(-1, (int)size_x, (int)size_y, (complex*)data, (complex*)comm, info);
	//cfft2dx(-2,scale, ltrans, inplace, size_x, size_y, (complex*)data, 1, size_x, (complex*)out, 1, size_y, (complex*)comm, info);
}

void cFFT::InitZFFT3D(long long size_x, long long size_y, long long size_z, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info)
{
	long long ltrans = 0;
	long long inplace = 0;
	cfft3dx(100, 1.0, ltrans, inplace,
		(int)size_x, (int)size_y, (int)size_z, (complex*)&data[0].Re, (complex*)&out[0].Re, (complex*)&comm[0].Re, info);

	return;
}

void cFFT::ZFFT3D(long long size_x, long long size_y, long long size_z, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info)
{
	long long ltrans = 0;
	long long inplace = 0;
	cfft3dx(-1, 1.0, ltrans, inplace,
		(int)size_x, (int)size_y, (int)size_z, (complex*)&data[0].Re, (complex*)&out[0].Re, (complex*)&comm[0].Re, info);

	return;
}

void cFFT::InitZFFT3Df(long long l, long long m, long long n, long long size_x, long long size_y, long long size_z, long long clen, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info)
{
	int ltrans = 1;
	int inplace = 1;
	cfft3dy(100, (float)scale, inplace,
		(int)l, (int)m, (int)n, (complex*)&data[0].Re, (int)1, (int)size_x, (int)size_x*size_y, (complex*)&out[0].Re, 1, l, (int)l * (int)m, (complex*)&comm[0].Re, (int)clen, info);

	return;
}

void cFFT::ZFFT3Df(long long l, long long m, long long n, long long size_x, long long size_y, long long size_z, long long clen, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info)
{
	long long ltrans = 1;
	long long inplace = 1;
	cfft3dy(-1, (float)scale, inplace,
		(int)l, (int)m, (int)n, (complex*)&data[0].Re, (int)1, (int)size_x, (int)size_x*size_y, (complex*)&out[0].Re, 1, l, (int)l * (int)m, (complex*)&comm[0].Re, (int)clen, info);

	return;
}
void cFFT::sZFFT3Df(long long l, long long m, long long n, long long size_x, long long size_y, long long size_z, long long clen, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info)
{
	long long ltrans = 1;
	long long inplace = 1;
	cfft3dy(-2, (float)scale, inplace,
		(int)l, (int)m, (int)n, (complex*)&data[0].Re, (int)1, (int)size_x, (int)size_x*size_y, (complex*)&out[0].Re, 1, l, (int)l * (int)m, (complex*)&comm[0].Re, (int)clen, info);

	return;
}
void cFFT::ZFFT1DM(long long N, long long M, long long stepx, long long stepy, COMPLEX* data, COMPLEX* comm, int* info)
{
	cfft1mx(-1, 1.0, 1, M, N, (complex*)&data[0].Re, stepx, stepy, NULL, stepx, stepy, (complex*)&comm[0].Re, info);
}
void cFFT::InitZFFT1DM(long long N, long long M, long long stepx, long long stepy, COMPLEX* data, COMPLEX* comm, int* info)
{
	cfft1mx(100, 1.0, 1, M, N, (complex*)&data[0].Re, stepx, stepy, NULL, stepx, stepy, (complex*)&comm[0].Re, info);
}
#pragma managed