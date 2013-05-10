#ifndef _N_VFFT_H
#define _N_VFFT_H

#pragma unmanaged

#include "acml.h"
#include "acml_mv.h"
#include "n_types.h"

//#include "acml_mv_m128.h"
class cFFT
{
public:	static float* window; // defines the array containing the profile of the temporal window
public:	static void GenerateWindow(long long type, long long size, double alpha);
private: static void GenWelchWin(float* win, long long size);
private: static void GenKieserWin(float* win, long long size, double alpha);
private: static void GenRectWin(float* win, long long size);
private: static void GenHammWin(float* win, long long size);


public: static void ApplyWindow1D(COMPLEX* data);
public: static void ApplyWindow2D(COMPLEX* data, long long size_x);
public: static void ApplyWindow3D(COMPLEX* data, long long size_x, long long size_y);
public: static void ApplyWindow4D(COMPLEX *data, long long bx, long long by, long long bz, long long wsize_x, long long wsize_y, long long wsize_z, long long size_x, long long size_y, long long size_z);

public: static void InitZFFT1D(long long size, COMPLEX* data, COMPLEX* comm, int* info);
public: static void InitZFFT1DM(long long N, long long M, long long stepx, long long stepy, COMPLEX* data, COMPLEX* comm, int* info);
public: static void InitZFFT1DSimple(long long size, COMPLEX* data, COMPLEX* comm, int* info);

public: static void InitZFFT2D(long long size_x, long long size_y, double scale, COMPLEX* data, COMPLEX* comm, COMPLEX* out, int* info);
public: static void InitZFFT3D(long long size_x, long long size_y, long long size_z, double scale, COMPLEX* data, COMPLEX* comm, COMPLEX* out, int* info);
public: static void InitZFFT3Df(long long l, long long m, long long n, long long size_x, long long size_y, long long size_z, long long clen, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info);

public: static void ZFFT1D(long long size, COMPLEX* data, COMPLEX* comm, int* info);
public: static void ZFFT1DM(long long N, long long M, long long stepx, long long stepy, COMPLEX* data, COMPLEX* comm, int* info);
public: static void ZFFT1DSimple(long long size, COMPLEX* data, COMPLEX* comm, int* info);
public: static void ZFFT2D(long long size_x, long long size_y, double scale, COMPLEX* data, COMPLEX* comm, COMPLEX* out, int* info);
public: static void ZFFT3D(long long size_x, long long size_y, long long size_z, double scale, COMPLEX* data, COMPLEX* comm, COMPLEX* out, int* info);
public: static void ZFFT3Df(long long l, long long m, long long n, long long size_x, long long size_y, long long size_z, long long clen, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info);
public: static void sZFFT3Df(long long l, long long m, long long n, long long size_x, long long size_y, long long size_z, long long clen, double scale, COMPLEX *data, COMPLEX *comm, COMPLEX *out, int* info);

public: static long long m_winsize;
public: static long long m_IsWindowGenerated;
public: static long long m_IsRectWindow;
};

#pragma managed

#endif