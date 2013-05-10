#ifndef _N_COMMON_FUNC_H
#define _N_COMMON_FUNC_H

#pragma unmanaged
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "n_types.h"

class cCommonFunc
{
public: static void pCharToUpperInplace(char* str);	
public: static void pRemoveSpacesInTheBegining(char* str);
public: static float pFindABSMaxIn2DArrayCMPX(long long sizeX, long long sizeY, COMPLEX *data);
public: static float pFindABSMinIn2DArrayCMPX(long long sizeX, long long sizeY, COMPLEX *data);
public: static COMPLEX pFindMaxAmpIn2DArrayCMPX(long long sizeX, long long sizeY, COMPLEX *data);
public: static COMPLEX pFindMinAmpIn2DArrayCMPX(long long sizeX, long long sizeY, COMPLEX *data);
};


inline long long p_addr_xy_v1(long long sizeX, long long i, long long j)
{
	const long long cmp = 1;
	return cmp * (sizeX*j+i);
}
inline long long p_addr_xy_v2(long long sizeX, long long i, long long j)
{
	const long long cmp = 2;
	return cmp * (sizeX*j+i);

}
inline long long p_addr_xy_v3(long long sizeX, long long i, long long j)
{
	const long long cmp = 3;
	return cmp * (sizeX*j+i);

}


inline long long p_addr_xyz_v1(long long sizeX, long long sizeY, long long i, long long j, long long k)
{
	const long long cmp = 1;
	return cmp * (sizeX*sizeY*k+sizeX*j+i);
}
inline long long p_addr_xyz_v2(long long sizeX, long long sizeY, long long i, long long j, long long k)
{
	const long long cmp = 2;
	return cmp * (sizeX*sizeY*k+sizeX*j+i);

}
inline long long p_addr_xyz_v3(long long sizeX, long long sizeY, long long i, long long j, long long k)
{
	const long long cmp = 3;
	return cmp * (sizeX*sizeY*k+sizeX*j+i);

}

inline long long p_addr_xyzt_v1(long long sizeX, long long sizeY, long long sizeZ, long long i, long long j, long long k, long long t)
{
	const long long cmp = 1;
	return cmp * (sizeX * sizeY * sizeZ * t + sizeX * sizeY * k + sizeX * j + i);
}
inline long long p_addr_xyzt_v2(long long sizeX, long long sizeY, long long sizeZ, long long i, long long j, long long k, long long t)
{
	const long long cmp = 2;
	return cmp * (sizeX * sizeY * sizeZ * t + sizeX * sizeY * k + sizeX * j + i);

}

inline long long p_addr_xyzt_v3(long long sizeX, long long sizeY, long long sizeZ, long long i, long long j, long long k, long long t)
{
	const long long cmp = 3;
	return cmp * (sizeX * sizeY * sizeZ * t + sizeX * sizeY * k + sizeX * j + i);

}

inline double besselI0(double x)
{
	        double xx,yy;

            if (x == 0.0)
            {
                return 1.0;
            }

            else
            {
                x *= x;
                xx = (x * (x * (x * (x * (x * (x * (x  * (x * (x * (x * (x * (x * (x *
                               (x * 0.210580722890567e-22 + 0.380715242345326e-19) +
                                   0.479440257548300e-16) + 0.435125971262668e-13) +
                                   0.300931127112960e-10) + 0.160224679395361e-7) +
                                   0.654858370096785e-5) + 0.202591084143397e-2) +
                                   0.463076284721000e0) + 0.754337328948189e2) +
                                   0.830792541809429e4) + 0.571661130563785e6) +
                                   0.216415572361227e8) + 0.356644482244025e9) +
                                   0.144048298227235e10);

                yy = (x * (x * (x - 0.307646912682801e4) +
                                 0.347626332405882e7) - 0.144048298227235e10);
            }

            return -xx / yy;
}
inline float log100f(float x)
{
	return logf(x)/logf(100);
}

inline float log1000f(float x)
{
	return logf(x)/logf(1000);
}

inline double df_dxi(double dx, double ym2, double ym1, double y1, double y2)
{
	return 0.1*(2.0*(y2-ym2)+(y1-ym1))/dx;
}

void getcolor(float value, unsigned char* color, long long is_positive, long long mode);

void getcolor_from_val(float value, unsigned char* color, long long is_positive);

void getcolor_from_val_bw(float value, unsigned char* color, long long is_positive);

void getcolor_from_val_smooth(float value, unsigned char* color, long long is_positive);

void getcolor_from_angle(float angle, unsigned char* color);

#pragma managed

#endif