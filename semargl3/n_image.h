#ifndef _N_IMAGE_H
#define _N_IMAGE_H

#include "n_types.h"
#pragma unmanaged

class cImage
{

public: static void DrawSampleXY(long long sizeX, long long sizeY, long long sizeZ, float *data, unsigned char *image, long long stride);
public: static void DrawSampleXZ(long long sizeX, long long sizeY, long long sizeZ, float *data, unsigned char *image, long long stride);
public: static void DrawSampleYZ(long long sizeX, long long sizeY, long long sizeZ, float *data, unsigned char *image, long long stride);

public: static void Draw2DRealDataRB(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br);
public: static void Draw2DRealDataRBAmp(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br);
public: static void DrawPostitive2DRealData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br, long long colorscale);
public: static void DrawAmp2DCMPXData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br, unsigned char* zero, long long colorscale, long long mode);
public: static void DrawPhase2DCMPXData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br);
public: static void DrawRe2DCMPXData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br);
public: static void DrawImg2DCMPXData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br);
};

#pragma managed
#endif