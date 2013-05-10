#include "n_common_func.h"
#include <math.h>
#pragma unmanaged

void cCommonFunc::pCharToUpperInplace(char *str)
{
	long long len = strlen(str);
	for (long long i=0;i<len;i++)
	{
		char c = str[i];
		if (__isascii(c) != 0)
		{
			if ( islower(c) != 0)
			{
				c = toupper(c);
				str[i]=c;
			}
		}
	}
}

void cCommonFunc::pRemoveSpacesInTheBegining(char *str)
{
	if (str == NULL) return;
	long long bs = 0;
	long long i = 0;
	//find the position
	while (str[bs] == ' ')
	{
		bs++;
	}
	//copy the data
	while (str[bs] != 0)
	{
		str[i] = str[bs];
		i++;
		bs++;
	}
	str[i] = 0;
}



float cCommonFunc::pFindABSMaxIn2DArrayCMPX(long long sizeX, long long sizeY, COMPLEX *data)
{
	long long size = sizeX * sizeY;
	float val = abs(data[0].Re);
	for (long long i = 1; i < size; i++)
	{
		float t_val = abs(data[i].Re);
		if (t_val > val) val = t_val;
	}
	return val;

}

float cCommonFunc::pFindABSMinIn2DArrayCMPX(long long sizeX, long long sizeY, COMPLEX *data)
{
	long long size = sizeX * sizeY;
	float val = abs(data[0].Re);
	for (long long i = 1; i < size; i++)
	{
		float t_val = abs(data[i].Re);
		if (t_val < val) val = t_val;
	}
	return val;

}


COMPLEX cCommonFunc::pFindMaxAmpIn2DArrayCMPX(long long sizeX, long long sizeY, COMPLEX* data)
{
	COMPLEX out;
	long long size = sizeX * sizeY;
	float val_re = data[0].Re;
	float val_img = data[0].Img;
	float amp = val_re * val_re + val_img * val_img;
	for (long long i = 1; i < size; i++)
	{
		float t_val_re = data[i].Re;
		float t_val_img = data[i].Img;

		float t_amp = t_val_re * t_val_re + t_val_img * t_val_img;
		if (t_amp > amp)
		{
			val_re = t_val_re;
			val_img = t_val_img;
			amp = t_amp;
		}

		//if (t_val_re > val_re) val_re = t_val_re;
		//if (t_val_img > val_img) val_img = t_val_img;
	}
	out.Re = val_re;
	out.Img = val_img;
	return out;

}

COMPLEX cCommonFunc::pFindMinAmpIn2DArrayCMPX(long long sizeX, long long sizeY, COMPLEX* data)
{
	COMPLEX out;
	long long size = sizeX * sizeY;
	float val_re = data[0].Re;
	float val_img = data[0].Img;
	float amp = val_re * val_re + val_img * val_img;
	for (long long i = 1; i < size; i++)
	{
		float t_val_re = data[i].Re;
		float t_val_img = data[i].Img;

		float t_amp = t_val_re * t_val_re + t_val_img * t_val_img;
		if (t_amp < amp)
		{
			val_re = t_val_re;
			val_img = t_val_img;
			amp = t_amp;
		}

		//if (t_val_re > val_re) val_re = t_val_re;
		//if (t_val_img > val_img) val_img = t_val_img;
	}
	out.Re = val_re;
	out.Img = val_img;
	return out;

}


void getcolor(float value, unsigned char* color, long long is_positive, long long mode)
{
	switch(mode)
	{
	case 0:
		getcolor_from_val(value, color, is_positive);
		break;
	case 1:
		getcolor_from_val_bw(value, color, is_positive);
		break;
	}
}
void getcolor_from_val(float value, unsigned char* color, long long is_positive)
{
	// B->BG->G->GR->R
	float val = value;
	if (val>1.0F) val = 1.0F;
	if (is_positive == 1 && val < 0.0F) val = 0.0F;
	if (is_positive != 1 && val < -1.0F) val = -1.0F;
	if (is_positive != 1) val = 0.5 * ( 1 + val );// clamp to the 0..1 region
	float n_val = 5 * MAX_CC_VAL * val;
	if (n_val < 255.0F)
	{
		color[0] = 0;
		color[1] = 0;
		color[2] = n_val/5;
		return;
	}

	if (n_val < 255.0F * 2.0F)
	{
		color[0] = 0;
		color[1] = n_val/5;
		color[2] = n_val/5;
		return;
	}

	if (n_val < 255.0F * 3.0F)
	{
		color[0] = 0;
		color[1] = n_val/5;
		color[2] = 0;
		return;
	}

	if (n_val < 255.0F * 4.0F)
	{
		color[0] = n_val/5;
		color[1] = n_val/5;
		color[2] = 0;
		return;
	}
	color[0] = n_val/5;
	color[1] = 0;
	color[2] = 0;
	return;

}

void getcolor_from_val_bw(float value, unsigned char* color, long long is_positive)
{
	// B->BG->G->GR->R
	float val = value;
	if (val>1.0F) val = 1.0F;
	if (is_positive == 1 && val < 0.0F) val = 0.0F;
	if (is_positive != 1 && val < -1.0F) val = -1.0F;
	if (is_positive != 1) val = 0.5 * ( 1 + val );// clamp to the 0..1 region
	val = 1.0f - val;
	int n_val = val * MAX_CC_VAL;
	color[0] = n_val;
	color[1] = n_val;
	color[2] = n_val;
	return;

}

void getcolor_from_val_smooth(float value, unsigned char* color, long long is_positive)
{
	// B->BG->G->GR->R
	float val = value;
	if (val>1.0F) val = 1.0F;
	if (is_positive == 1 && val < 0.0F) val = 0.0F;
	if (is_positive != 1 && val < -1.0F) val = -1.0F;
	if (is_positive != 1) val = 0.5 * ( 1 + val );// clamp to the 0..1 region
	
	float PI = 4.0F * atanf(1.0F);
	float H = 2 * PI * val; // HUE

	long long R = 255;
    long long G = 255;
    long long B = 255;

	float S = 1.0f - val; // SATURATION
	float V = val; // INTENSITY

	if (H > 2.0F * PI) H = (float)(H - 2.0F * PI);
    if (H < 0) H = (float)(2.0F * PI + H);


    float hi = (float)floorf(3.0F * H / PI);

    float f = (float)((3.0F * H / PI) - (float)hi);

    long long ihi = abs(hi);

    float p = V * (1.0F - S);
    float q = V * (1.0F - f * S);
    float t = V * (1.0F - ((1.0F - f) * S));

    switch (ihi)
    {
        case 0:
            R = (255.0f * V);
            G = (255.0f * t);
            B = (255.0f * p);
            break;
        case 1:
            R = (255.0f * q);
            G = (255.0f * V);
            B = (255.0f * p);
            break;
        case 2:
            R = (255.0f * p);
            G = (255.0f * V);
            B = (255.0f * t);
            break;
        case 3:
            R = (255.0f * p);
            G = (255.0f * q);
            B = (255.0f * V);
            break;
        case 4:
            R = (255.0f * t);
            G = (255.0f * p);
            B = (255.0f * V);
            break;
        default:
            R = (255.0f * V);
            G = (255.0f * p);
            B = (255.0f * q);
            break;
    }
	color[0] = (unsigned char)R;
	color[1] = (unsigned char)G;
	color[2] = (unsigned char)B;
	return;

}

void getcolor_from_angle(float angle, unsigned char* color)
{
	float PI = 4.0F * atanf(1.0F);
	float H = angle; // HUE

	long long R = 255;
    long long G = 255;
    long long B = 255;

	float S = 1; // SATURATION
	float V = 1; // INTENSITY

	if (H > 2.0F * PI) H = (float)(H - 2.0F * PI);
    if (H < 0) H = (float)(2.0F * PI + H);


    float hi = (float)floorf(3.0F * H / PI);

    float f = (float)((3.0F * H / PI) - (float)hi);

    long long ihi = abs(hi);

    float p = V * (1.0F - S);
    float q = V * (1.0F - f * S);
    float t = V * (1.0F - ((1.0F - f) * S));

    switch (ihi)
    {
        case 0:
            R = (255.0f * V);
            G = (255.0f * t);
            B = (255.0f * p);
            break;
        case 1:
            R = (255.0f * q);
            G = (255.0f * V);
            B = (255.0f * p);
            break;
        case 2:
            R = (255.0f * p);
            G = (255.0f * V);
            B = (255.0f * t);
            break;
        case 3:
            R = (255.0f * p);
            G = (255.0f * q);
            B = (255.0f * V);
            break;
        case 4:
            R = (255.0f * t);
            G = (255.0f * p);
            B = (255.0f * V);
            break;
        default:
            R = (255.0f * V);
            G = (255.0f * p);
            B = (255.0f * q);
            break;
    }
	color[0] = (unsigned char)R;
	color[1] = (unsigned char)G;
	color[2] = (unsigned char)B;
	return;
}
#pragma managed