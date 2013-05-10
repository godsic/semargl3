#include "n_txtwriter.h"
#include <stdlib.h>
#include <stdio.h>
#include "n_common_func.h"
long long cTXTWriter::SaveToFileNCMPX(COMPLEX *data, long long sizex, long long sizey, long long sizez, long long sizet, 
								double cs_x, double cs_y, double cs_z, double cs_t, 
								long long max_x, long long max_y, long long max_z, long long max_t, long long regime, char *filename, char *header)
{
	long long stepx = sizex / max_x;
	long long stepy = sizey / max_y;
	long long stepz = sizez / max_z;
	long long stept = sizet / max_t;
	if (stepx == 0) stepx++;
	if (stepy == 0) stepy++;
	if (stepz == 0) stepz++;
	if (stept == 0) stept++;

	FILE* file = fopen(filename, "wt");
	fprintf(file, "%s", header); 
	switch(regime)
	{
	case 0:
		// 1D
		fprintf(file, "X\tRe\tImg\n");
		for (long long i=0; i < sizex; i+=stepx)
		{
			float x = i * cs_x;
			float Re = data[i].Re;
			float Img = data[i].Img;
			fprintf(file, "%.8g\t%.8g\t%.8g\n", x, Re, Img);
		}
		break;
	case 1:
		// 2D
		fprintf(file, "X\tY\tRe\tImg\n");
		for (long long j=0; j < sizey; j+=stepy)
		{
			float y = j * cs_y;
			for (long long i = 0; i < sizex; i+=stepx)
			{
				float x = i * cs_x;
				long long addr = p_addr_xy_v1(sizex, i, j);
				float Re = data[addr].Re;
				float Img = data[addr].Img;
				fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\n", x, y, Re, Img);
			}
		}
		break;
	case 2:
		// 3D
		fprintf(file, "X\tY\tZ\tRe\tImg\n");
		for (long long k=0; k <sizez; k += stepz)
		{
			float z = k * cs_z;
			for (long long j=0; j < sizey; j += stepy)
			{
				float y = j * cs_y;
				for (long long i = 0; i < sizex; i += stepx)
				{
					float x = i * cs_x;
					long long addr = p_addr_xyz_v1(sizex, sizey, i, j, k);
					float Re = data[addr].Re;
					float Img = data[addr].Img;
					fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Re, Img);
				}
			}
		}
		break;
	case 3:
		// 4D
		fprintf(file, "X\tY\tZ\tT\tRe\tImg\n");
		for (long long p = 0; p < sizet; p += stept)
		{
			float t= p * cs_t;
			for (long long k=0; k <sizez; k += stepz)
			{
				float z = k * cs_z;
				for (long long j=0; j < sizey; j += stepy)
				{
					float y = j * cs_y;
					for (long long i = 0; i < sizex; i += stepx)
					{
						float x = i * cs_x;
						long long addr = p_addr_xyzt_v1(sizex, sizey, sizez, i, j, k, p);
						float Re = data[addr].Re;
						float Img = data[addr].Img;
						fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Re, Img);
					}
				}
			}
		}
		break;
	}
	fclose(file);
	return 0;
}


long long cTXTWriter::SaveToFileReCMPX(COMPLEX *data, long long sizex, long long sizey, long long sizez, long long sizet, 
								 double cs_x, double cs_y, double cs_z, double cs_t, 
								 long long max_x, long long max_y, long long max_z, long long max_t, long long regime, char *filename, char *header)
{
	long long stepx = sizex / max_x;
	long long stepy = sizey / max_y;
	long long stepz = sizez / max_z;
	long long stept = sizet / max_t;
	if (stepx == 0) stepx++;
	if (stepy == 0) stepy++;
	if (stepz == 0) stepz++;
	if (stept == 0) stept++;
	FILE* file = fopen(filename, "wt");
	fprintf(file, "%s", header); 
	switch(regime)
	{
	case 0:
		// 1D
		fprintf(file, "X\tRe\n");
		for (long long i=0; i < sizex; i+=stepx)
		{
			float x = i * cs_x;
			double Re = data[i].Re;
			fprintf(file, "%.8g\t%.8g\n", x, Re);
		}
		break;
	case 1:
		// 2D
		fprintf(file, "X\tY\tRe\n");
		for (long long j=0; j < sizey; j+=stepy)
		{
			float y = j * cs_y;
			for (long long i = 0; i < sizex; i+=stepx)
			{
				float x = i * cs_x;
				long long addr = p_addr_xy_v1(sizex, i, j);
				float Re = data[addr].Re;
				fprintf(file, "%.8g\t%.8g\t%.8g\n", x, y, Re);
			}
		}
		break;
	case 2:
		// 3D
		fprintf(file, "X\tY\tZ\tRe\n");
		for (long long k=0; k <sizez; k += stepz)
		{
			float z = k * cs_z;
			for (long long j=0; j < sizey; j += stepy)
			{
				float y = j * cs_y;
				for (long long i = 0; i < sizex; i += stepx)
				{
					float x = i * cs_x;
					long long addr = p_addr_xyz_v1(sizex, sizey, i, j, k);
					float Re = data[addr].Re;
					fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Re);
				}
			}
		}
		break;
	case 3:
		// 4D
		fprintf(file, "X\tY\tZ\tT\tRe\n");
		for (long long p = 0; p < sizet; p += stept)
		{
			float t= p * cs_t;
			for (long long k=0; k <sizez; k += stepz)
			{
				float z = k * cs_z;
				for (long long j=0; j < sizey; j += stepy)
				{
					float y = j * cs_y;
					for (long long i = 0; i < sizex; i += stepx)
					{
						float x = i * cs_x;
						long long addr = p_addr_xyzt_v1(sizex, sizey, sizez, i, j, k, p);
						float Re = data[addr].Re;
						fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Re);
					}
				}
			}
		}
		break;
	}
	fclose(file);
	return 0;
}
long long cTXTWriter::SaveToFileImgCMPX(COMPLEX *data, long long sizex, long long sizey, long long sizez, long long sizet, 
								  double cs_x, double cs_y, double cs_z, double cs_t, 
								  long long max_x, long long max_y, long long max_z, long long max_t, long long regime, char *filename, char *header)
{
	
	long long stepx = sizex / max_x;
	long long stepy = sizey / max_y;
	long long stepz = sizez / max_z;
	long long stept = sizet / max_t;
	if (stepx == 0) stepx++;
	if (stepy == 0) stepy++;
	if (stepz == 0) stepz++;
	if (stept == 0) stept++;
	FILE* file = fopen(filename, "wt");
	fprintf(file, "%s", header); 
	switch(regime)
	{
	case 0:
		// 1D
		fprintf(file, "X\tImg\n");
		for (long long i=0; i < sizex; i+=stepx)
		{
			float x = i * cs_x;
			float Img = data[i].Img;
			fprintf(file, "%.8g\t%.8g\n", x, Img);
		}
		break;
	case 1:
		// 2D
		fprintf(file, "X\tY\tImg\n");
		for (long long j=0; j < sizey; j+=stepy)
		{
			float y = j * cs_y;
			for (long long i = 0; i < sizex; i+=stepx)
			{
				float x = i * cs_x;
				long long addr = p_addr_xy_v1(sizex, i, j);
				float Img = data[addr].Img;
				fprintf(file, "%.8g\t%.8g\t%.8g\n", x, y, Img);
			}
		}
		break;
	case 2:
		// 3D
		fprintf(file, "X\tY\tZ\tImg\n");
		for (long long k=0; k <sizez; k += stepz)
		{
			float z = k * cs_z;
			for (long long j=0; j < sizey; j += stepy)
			{
				float y = j * cs_y;
				for (long long i = 0; i < sizex; i += stepx)
				{
					float x = i * cs_x;
					long long addr = p_addr_xyz_v1(sizex, sizey, i, j, k);
					float Img = data[addr].Img;
					fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Img);
				}
			}
		}
		break;
	case 3:
		// 4D
		fprintf(file, "X\tY\tZ\tT\tImg\n");
		for (long long p = 0; p < sizet; p += stept)
		{
			float t= p * cs_t;
			for (long long k=0; k <sizez; k += stepz)
			{
				float z = k * cs_z;
				for (long long j=0; j < sizey; j += stepy)
				{
					float y = j * cs_y;
					for (long long i = 0; i < sizex; i += stepx)
					{
						float x = i * cs_x;
						long long addr = p_addr_xyzt_v1(sizex, sizey, sizez, i, j, k, p);
						float Img = data[addr].Img;
						fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Img);
					}
				}
			}
		}
		break;
	}
	fclose(file);
	return 0;
}
long long cTXTWriter::SaveToFileAPCMPX(COMPLEX *data, long long sizex, long long sizey, long long sizez, long long sizet, 
								 double cs_x, double cs_y, double cs_z, double cs_t, 
								 long long max_x, long long max_y, long long max_z, long long max_t, long long regime, char *filename, char *header)
{
	long long stepx = sizex / max_x;
	long long stepy = sizey / max_y;
	long long stepz = sizez / max_z;
	long long stept = sizet / max_t;
	if (stepx == 0) stepx++;
	if (stepy == 0) stepy++;
	if (stepz == 0) stepz++;
	if (stept == 0) stept++;
	FILE* file = fopen(filename, "wt");
	fprintf(file, "%s", header); 
	switch(regime)
	{
	case 0:
		// 1D
		fprintf(file, "X\tAmp\tPhase\n");
		for (long long i=0; i < sizex; i+=stepx)
		{
			float x = i * cs_x;
			float Re = data[i].Re;
			float Img = data[i].Img;
			float Amp = sqrtf(Re*Re + Img*Img);
			float Phz = atan2f(Img, Re);
			fprintf(file, "%.8g\t%.8g\t%.8g\n", x, Amp, Phz);
		}
		break;
	case 1:
		// 2D
		fprintf(file, "X\tY\tAmp\tPhase\n");
		for (long long j=0; j < sizey; j+=stepy)
		{
			float y = j * cs_y;
			for (long long i = 0; i < sizex; i+=stepx)
			{
				float x = i * cs_x;
				long long addr = p_addr_xy_v1(sizex, i, j);
				float Re = data[addr].Re;
				float Img = data[addr].Img;
				float Amp = sqrtf(Re*Re + Img*Img);
				float Phz = atan2f(Img, Re);
				fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\n", x, y, Amp, Phz);
			}
		}
		break;
	case 2:
		// 3D
		fprintf(file, "# X\tY\tZ\tAmp\tPhz\n");
		for (long long k=0; k <sizez; k += stepz)
		{
			float z = k * cs_z;
			for (long long j=0; j < sizey; j += stepy)
			{
				float y = j * cs_y;
				for (long long i = 0; i < sizex; i += stepx)
				{
					float x = i * cs_x;
					long long addr = p_addr_xyz_v1(sizex, sizey, i, j, k);
					float Re = data[addr].Re;
					float Img = data[addr].Img;
					float Amp = sqrtf(Re*Re + Img*Img);
					float Phz = atan2f(Img, Re);
					fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Amp, Phz);
				}
			}
		}
		break;
	case 3:
		// 4D
		fprintf(file, "X\tY\tZ\tT\tRe\tImg\n");
		for (long long p = 0; p < sizet; p += stept)
		{
			float t= p * cs_t;
			for (long long k=0; k <sizez; k += stepz)
			{
				float z = k * cs_z;
				for (long long j=0; j < sizey; j += stepy)
				{
					float y = j * cs_y;
					for (long long i = 0; i < sizex; i += stepx)
					{
						float x = i * cs_x;
						long long addr = p_addr_xyzt_v1(sizex, sizey, sizez, i, j, k, p);
						float Re = data[addr].Re;
						float Img = data[addr].Img;
						float Amp = sqrtf(Re*Re + Img*Img);
						float Phz = atan2f(Img, Re);
						fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Amp, Phz);
					}
				}
			}
		}
		break;
	}
	fclose(file);
	return 0;
}

long long cTXTWriter::SaveToFileReal(float *data, long long sizex, long long sizey, long long sizez, long long sizet, 
							   double cs_x, double cs_y, double cs_z, double cs_t, 
							   long long max_x, long long max_y, long long max_z, long long max_t, long long regime, char *filename, char *header)
{
	long long stepx = sizex / max_x;
	long long stepy = sizey / max_y;
	long long stepz = sizez / max_z;
	long long stept = sizet / max_t;
	if (stepx == 0) stepx++;
	if (stepy == 0) stepy++;
	if (stepz == 0) stepz++;
	if (stept == 0) stept++;
	FILE* file = fopen(filename, "wt");
	fprintf(file, "%s", header); 
	switch(regime)
	{
	case 0:
		// 1D
		fprintf(file, "X\tValue\n");
		for (long long i=0; i < sizex; i+=stepx)
		{
			float x = i * cs_x;
			double Re = data[i];
			fprintf(file, "%.8g\t%.8g\n", x, Re);
		}
		break;
	case 1:
		// 2D
		fprintf(file, "X\tY\tValue\n");
		for (long long j=0; j < sizey; j+=stepy)
		{
			float y = j * cs_y;
			for (long long i = 0; i < sizex; i+=stepx)
			{
				float x = i * cs_x;
				long long addr = p_addr_xy_v1(sizex, i, j);
				float Re = data[addr];
				fprintf(file, "%.8g\t%.8g\t%.8g\n", x, y, Re);
			}
		}
		break;
	case 2:
		// 3D
		fprintf(file, "X\tY\tZ\tValue\n");
		for (long long k=0; k <sizez; k += stepz)
		{
			float z = k * cs_z;
			for (long long j=0; j < sizey; j += stepy)
			{
				float y = j * cs_y;
				for (long long i = 0; i < sizex; i += stepx)
				{
					float x = i * cs_x;
					long long addr = p_addr_xyz_v1(sizex, sizey, i, j, k);
					float Re = data[addr];
					fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Re);
				}
			}
		}
		break;
	case 3:
		// 4D
		fprintf(file, "X\tY\tZ\tT\tValue\n");
		for (long long p = 0; p < sizet; p += stept)
		{
			float t= p * cs_t;
			for (long long k=0; k <sizez; k += stepz)
			{
				float z = k * cs_z;
				for (long long j=0; j < sizey; j += stepy)
				{
					float y = j * cs_y;
					for (long long i = 0; i < sizex; i += stepx)
					{
						float x = i * cs_x;
						long long addr = p_addr_xyzt_v1(sizex, sizey, sizez, i, j, k, p);
						float Re = data[addr];
						fprintf(file, "%.8g\t%.8g\t%.8g\t%.8g\t%.8g\n", x, y, z, Re);
					}
				}
			}
		}
		break;
	}
	fclose(file);
	return 0;
}

long long cTXTWriter::SaveToFile(float *data, long long sizex, long long sizey, long long sizez, long long sizet, 
						   double cs_x, double cs_y, double cs_z, double cs_t, 
						   long long max_x, long long max_y, long long max_z, long long max_t, long long regime, long long datatype, 
						   char *filename, char *header)
{
	long long result = 0;
	switch(datatype)
	{
	case save_datatype::REAL:
		result = SaveToFileReal(data, sizex, sizey, sizez, sizet,
			cs_x, cs_y,cs_z,cs_t, max_x, max_y, max_z, max_t, regime, filename, header);
		break;
	case save_datatype::CMPX:
		result = SaveToFileNCMPX((COMPLEX*)data, sizex, sizey, sizez, sizet,
			cs_x, cs_y,cs_z,cs_t, max_x, max_y, max_z, max_t, regime, filename, header);
		break;
	case save_datatype::CMPX_RE:
		result = SaveToFileReCMPX((COMPLEX*)data, sizex, sizey, sizez, sizet,
			cs_x, cs_y,cs_z,cs_t, max_x, max_y, max_z, max_t, regime, filename, header);
		break;
	case save_datatype::CMPX_IMG:
		result = SaveToFileImgCMPX((COMPLEX*)data, sizex, sizey, sizez, sizet,
			cs_x, cs_y,cs_z,cs_t, max_x, max_y, max_z, max_t, regime, filename, header);
		break;
	case save_datatype::CMPX_AP:
		result = SaveToFileAPCMPX((COMPLEX*)data, sizex, sizey, sizez, sizet,
			cs_x, cs_y,cs_z,cs_t, max_x, max_y, max_z, max_t, regime, filename, header);
		break;
	}
	return result;
}

