#include "n_image.h"
#include "n_common_func.h"
#include "n_types.h"
#include <math.h>
#include <ppl.h>

using namespace Concurrency;

void cImage::DrawSampleXY(long long sizeX, long long sizeY, long long sizeZ, float *data, unsigned char *image, long long stride)
{
	long long size_v3 = 3 * sizeX;
	long long size = size_v3 * sizeY;

	for (long long j=0;j<sizeY;j++)
	{
		for (long long i=0; i<sizeX;i++)
		{
			long long addrXY = size_v3*j + 3 * i;
			double val = data[addrXY]*data[addrXY] + data[addrXY+1]*data[addrXY+1] + data[addrXY+2]*data[addrXY+2];
			if (val!=0.0)
			{
				long long addr1 = stride * j + 3 * i;
				image[addr1] = (unsigned char)255;
				image[addr1+1] = (unsigned char)255;
				image[addr1+2] = (unsigned char)255;
			}
		}
	}
}

void cImage::DrawSampleXZ(long long sizeX, long long sizeY, long long sizeZ, float *data, unsigned char *image, long long stride)
{
	long long size_v3 = 3 * sizeX;

	for (long long k = 0; k < sizeZ;k++)
	{
		for (long long i=0;i < sizeX;i++)
		{
			long long addrXZ = size_v3 * sizeY * k + 3 * i;
			double val = data[addrXZ]*data[addrXZ] + data[addrXZ+1]*data[addrXZ+1] + data[addrXZ+2]*data[addrXZ+2];
			if (val!=0.0)
			{
				long long addr1 = stride * k + 3 * i;
				image[addr1] = 255;
				image[addr1+1] = 255;
				image[addr1+2] = 255;
			}
		}
	}

}

void cImage::DrawSampleYZ(long long sizeX, long long sizeY, long long sizeZ, float *data, unsigned char *image, long long stride)
{
	long long size_v3 = 3 * sizeX;

	for (long long k = 0; k < sizeZ;k++)
	{
		for (long long j=0; j < sizeY; j++)
		{
			long long addrYZ =  size_v3 * sizeY *k + size_v3 * j;
			double val = data[addrYZ]*data[addrYZ] + data[addrYZ+1]*data[addrYZ+1] + data[addrYZ+2]*data[addrYZ+2];
			if (val!=0.0)
			{
				long long addr1 = stride * k + 3 * j;
				image[addr1] = 255;
				image[addr1+1] = 255;
				image[addr1+2] = 255;
			}
		}
	}

}
void cImage::Draw2DRealDataRB(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br)
{
	float max = cCommonFunc::pFindABSMaxIn2DArrayCMPX(sizeX, sizeY, data_2d);
	float norm = br * MAX_CC_VAL / max; // clamp to -MAX_CC_VAL to MAX_CC_VAL
	unsigned char G = 0;
	for (long long j = 0; j < sizeY; j++)
	{
		for (long long i = 0; i < sizeX; i++)
		{
			unsigned char R = 0;
			unsigned char B = 0;
			unsigned char G = 0;
			long long addr = p_addr_xy_v1(sizeX, i, j);
			float val = data_2d[addr].Re;
			val *= norm;
			if (val > MAX_CC_VAL) val = MAX_CC_VAL;
			if (val < -MAX_CC_VAL) val = -MAX_CC_VAL;
			if (val != 0.0F)
			{
				G = 0;
				long long ival = floor(val);
				if (ival<0)
				{
					//R = 0;
					//B = -ival;
					B = MAX_CC_VAL;
					R = MAX_CC_VAL + ival;
					G = MAX_CC_VAL + ival;
				}
				else
				{
					//R = ival;
					//B = 0;
					R = MAX_CC_VAL;
					G = MAX_CC_VAL - ival;
					B = MAX_CC_VAL - ival;
				}
			}
			

			long long iaddr = stride * j + 3 * i;
			image[iaddr] = B;
			image[iaddr + 1] = G;
			image[iaddr + 2] = R;
		}
	}
}

void cImage::Draw2DRealDataRBAmp(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br)
{
	float max = cCommonFunc::pFindABSMaxIn2DArrayCMPX(sizeX, sizeY, data_2d);
	float norm = br * MAX_CC_VAL / max; // clamp to -MAX_CC_VAL to MAX_CC_VAL
	unsigned char G = 0;
	for (long long j = 0; j < sizeY; j++)
	{
		for (long long i = 0; i < sizeX; i++)
		{
			unsigned char R = 0;
			unsigned char B = 0;
			unsigned char G = 0;
			long long addr = p_addr_xy_v1(sizeX, i, j);
			float val = abs(data_2d[addr].Re);
			val *= norm;
			if (val > MAX_CC_VAL) val = MAX_CC_VAL;
			if (val != 0.0F)
			{
				long long ival = floor(val);
				G = ival;
				B = ival;
				R = ival;
			}
			long long iaddr = stride * j + 3 * i;
			image[iaddr] = B;
			image[iaddr + 1] = G;
			image[iaddr + 2] = R;
		}
	}
}


void cImage::DrawAmp2DCMPXData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br, unsigned char* zero, long long colorscale, long long mode)
{
	COMPLEX max = cCommonFunc::pFindMaxAmpIn2DArrayCMPX(sizeX, sizeY, data_2d);
	COMPLEX min = cCommonFunc::pFindMinAmpIn2DArrayCMPX(sizeX, sizeY, data_2d);
	float maamp = (float)sqrtf(max.Re * max.Re + max.Img * max.Img);
	float miamp = (float)sqrtf(min.Re * min.Re + min.Img * min.Img);

	if (miamp == 0.0F) miamp = 1e-12F;
	float rg = maamp - miamp;
	float logmin = 0.0F;
	float logmaxmin = 0.0F;
	float norm = 1.0F / rg ;
	float brnorm = br * norm;
	switch(colorscale)
	{
	case 0:
		// Linear scale
		parallel_for(long long (0), sizeY, [&](long long j)
		//for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				unsigned char RGB[3] = {zero[0], zero[1], zero[2]};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = sqrtf(data_2d[addr].Re * data_2d[addr].Re + data_2d[addr].Img * data_2d[addr].Img);
				if (val != 0.0F)
				{
					val -= miamp;
					val *= brnorm;
					getcolor(val, &RGB[0], 1, mode);
				}
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		});
		break;
	case 1:
		// LOG10 scale
		logmin = log10f(miamp);
		logmaxmin = log10f(br) / (log10f(maamp)-log10f(miamp));
		parallel_for(long long (0), sizeY, [&](long long j)
		//for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				//unsigned char RGB[3] = {zero[0], zero[1], zero[2]};
				unsigned char RGB[3] = {255, 255, 255};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = sqrtf(data_2d[addr].Re * data_2d[addr].Re + data_2d[addr].Img * data_2d[addr].Img);
				val = (log10f(val) - logmin) * logmaxmin;
				if (val != 0.0F) getcolor(val, &RGB[0], 1, mode);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		});
		break;
	case 2:
		// SQRT scale
		parallel_for(long long (0), sizeY, [&](long long j)
		//for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				//unsigned char RGB[3] = {zero[0], zero[1], zero[2]};
				unsigned char RGB[3] = {255, 255, 255};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = sqrtf(data_2d[addr].Re * data_2d[addr].Re + data_2d[addr].Img * data_2d[addr].Img);
				val -= miamp;
				val *= norm;
				val = sqrt(br) * sqrtf(val);
				if (val != 0.0F) getcolor(val, &RGB[0], 1, mode);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		});
		break;
	case 3:
		// 2SQRT scale
		
		parallel_for(long long (0), sizeY, [&](long long j)
		//for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				//unsigned char RGB[3] = {zero[0], zero[1], zero[2]};
				unsigned char RGB[3] = {255, 255, 255};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = sqrtf(data_2d[addr].Re * data_2d[addr].Re + data_2d[addr].Img * data_2d[addr].Img);
				val -= miamp;
				val *= norm;
				val = sqrtf(sqrtf(br)) * sqrt(sqrtf(val));
				if (val != 0.0F) getcolor(val, &RGB[0], 1, mode);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		});
		break;
	case 4:
		// LOG100 scale
		logmin = log100f(miamp);
		logmaxmin = log100f(br) / (log100f(maamp)-log100f(miamp));
		parallel_for(long long (0), sizeY, [&](long long j)
		//for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				//unsigned char RGB[3] = {zero[0], zero[1], zero[2]};
				unsigned char RGB[3] = {255, 255, 255};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = sqrtf(data_2d[addr].Re * data_2d[addr].Re + data_2d[addr].Img * data_2d[addr].Img);
				val = (log100f(val) - logmin) * logmaxmin;
				if (val != 0.0F) getcolor(val, &RGB[0], 1, mode);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		});
		break;
	case 5:
		// X^2 scale
		parallel_for(long long (0), sizeY, [&](long long j)
		//for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				//unsigned char RGB[3] = {zero[0], zero[1], zero[2]};
				unsigned char RGB[3] = {255, 255, 255};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = sqrtf(data_2d[addr].Re * data_2d[addr].Re + data_2d[addr].Img * data_2d[addr].Img);
				val -= miamp;
				val *= norm;
				val = (br * br) * (val * val);
				if (val != 0.0F) getcolor(val, &RGB[0], 1, mode);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		});
		break;
	}
}

void cImage::DrawPhase2DCMPXData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br)
{
	float PI = 4 * atanf(1.0F);
	for (long long j = 0; j < sizeY; j++)
	{
		for (long long i = 0; i < sizeX; i++)
		{
			unsigned char RGB[3] = {FILLCOLOUR, FILLCOLOUR, FILLCOLOUR};

			long long addr = p_addr_xy_v1(sizeX, i, j);
			long long iaddr = stride * j + 3 * i;

			float Re = data_2d[addr].Re;
			float Img = data_2d[addr].Img;	

			if (Re + Img != 0.0F)
			{
				float val = PI + atan2f(Img, Re);
				getcolor_from_angle(val, &RGB[0]);
			}	
			image[iaddr] = RGB[2];
			image[iaddr + 1] = RGB[1];
			image[iaddr + 2] = RGB[0];
		}
	}
}

void cImage::DrawRe2DCMPXData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br)
{
	COMPLEX max = cCommonFunc::pFindMaxAmpIn2DArrayCMPX(sizeX, sizeY, data_2d);
	float norm = br * 1.0F / (float)sqrtf(max.Re*max.Re + max.Img*max.Img);
	for (long long j = 0; j < sizeY; j++)
	{
		for (long long i = 0; i < sizeX; i++)
		{
			unsigned char RGB[3] = {FILLCOLOUR, FILLCOLOUR, FILLCOLOUR};
			long long addr = p_addr_xy_v1(sizeX, i, j);
			float val = data_2d[addr].Re;
			val *= norm;
			if (val != 0.0F) getcolor_from_val(val, &RGB[0], 0);
			long long iaddr = stride * j + 3 * i;
			image[iaddr] = RGB[2];
			image[iaddr + 1] = RGB[1];
			image[iaddr + 2] = RGB[0];
		}
	}

}

void cImage::DrawImg2DCMPXData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br)
{
	COMPLEX max = cCommonFunc::pFindMaxAmpIn2DArrayCMPX(sizeX, sizeY, data_2d);
	float norm = br * 1.0F / (float)sqrtf(max.Re*max.Re + max.Img*max.Img);
	for (long long j = 0; j < sizeY; j++)
	{
		for (long long i = 0; i < sizeX; i++)
		{
			unsigned char RGB[3] = {FILLCOLOUR, FILLCOLOUR, FILLCOLOUR};
			long long addr = p_addr_xy_v1(sizeX, i, j);
			float val = data_2d[addr].Img;
			val *= norm;
			if (val != 0.0F) getcolor_from_val(val, &RGB[0], 0);
			long long iaddr = stride * j + 3 * i;
			image[iaddr] = RGB[2];
			image[iaddr + 1] = RGB[1];
			image[iaddr + 2] = RGB[0];
		}
	}

}

void cImage::DrawPostitive2DRealData(long long sizeX, long long sizeY, COMPLEX *data_2d, unsigned char *image, long long stride, float br, long long colorscale)
{
	float max = cCommonFunc::pFindABSMaxIn2DArrayCMPX(sizeX, sizeY, data_2d);
	float min = cCommonFunc::pFindABSMinIn2DArrayCMPX(sizeX, sizeY, data_2d);
	if (min == 0.0F) min = 1e-12F;
	float logmin = 0.0f;
	float logmaxmin = 0.0f;
	float norm = 1.0F / (max-min);
	float brnorm = br * norm;
	switch (colorscale)
	{
	case 0:
		// Linear scale
#pragma omp parallel for
		for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				unsigned char RGB[3] = {FILLCOLOUR, FILLCOLOUR, FILLCOLOUR};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = data_2d[addr].Re;
				val -= min;
				val *= brnorm;
				if (val != 0.0F) getcolor_from_val(val, &RGB[0], 1);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		}
		break;
	case 1:

		// Log10 scale
		logmin = log10f(min);
		logmaxmin = log10f(br) / (log10f(max)-log10f(min));
#pragma omp parallel for
		for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				unsigned char RGB[3] = {FILLCOLOUR, FILLCOLOUR, FILLCOLOUR};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = data_2d[addr].Re;
				//val *= norm;
				val = (log10f(val) - logmin) * logmaxmin;
				if (val != 0.0F) getcolor_from_val(val, &RGB[0], 1);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		}
		break;
	case 2:
		// Sqrt scale
#pragma omp parallel for
		for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				unsigned char RGB[3] = {FILLCOLOUR, FILLCOLOUR, FILLCOLOUR};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = data_2d[addr].Re;
				val -= min;
				val *= norm;
				val = sqrtf(br) * sqrtf(val);
				if (val != 0.0F) getcolor_from_val(val, &RGB[0], 1);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		}
		break;
	case 3:
		// 2SQRT scale
#pragma omp parallel for
		for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				unsigned char RGB[3] = {FILLCOLOUR, FILLCOLOUR, FILLCOLOUR};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = data_2d[addr].Re;
				val -= min;
				val *= norm;
				val = sqrtf(sqrtf(br)) * sqrtf(sqrtf(val));
				if (val != 0.0F) getcolor_from_val(val, &RGB[0], 1);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		}
		break;
	case 4:
		// Log100 scale
		logmin = log100f(min);
		logmaxmin = log100f(br) / (log100f(max)-log100f(min));
#pragma omp parallel for
		for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				unsigned char RGB[3] = {FILLCOLOUR, FILLCOLOUR, FILLCOLOUR};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = data_2d[addr].Re;
				//val *= norm;
				val = (log100f(val) - logmin) * logmaxmin;
				if (val != 0.0F) getcolor_from_val(val, &RGB[0], 1);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		}
		break;
	case 5:
		// Log1000 scale
		logmin = log1000f(min);
		logmaxmin = log1000f(br) / (log1000f(max)-log1000f(min));
#pragma omp parallel for
		for (long long j = 0; j < sizeY; j++)
		{
			for (long long i = 0; i < sizeX; i++)
			{
				unsigned char RGB[3] = {FILLCOLOUR, FILLCOLOUR, FILLCOLOUR};
				long long addr = p_addr_xy_v1(sizeX, i, j);
				float val = data_2d[addr].Re;
				//val *= norm;
				val = (log1000f(val) - logmin) * logmaxmin;
				if (val != 0.0F) getcolor_from_val(val, &RGB[0], 1);
				long long iaddr = stride * j + 3 * i;
				image[iaddr] = RGB[2];
				image[iaddr + 1] = RGB[1];
				image[iaddr + 2] = RGB[0];
			}
		}
		break;
	}

}