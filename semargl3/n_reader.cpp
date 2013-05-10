#include "n_reader.h"

#pragma unmanaged

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <memory.h>
//#include <fstream>
//#include <iostream>
//
//using namespace std;

long long cReader::ProbeParametersOfSimulations(char* s_name, char **names, long long num_files, cMagnetization *t_mag)
{
	SIMPARAMS t_simparams;
	t_simparams.m_NumberOfTimeSteps = num_files;
	if (GetSimulationsParameters(names[num_files-1],
									&t_simparams) != 0)
	{
		return 1;
	}

	long long str_len = 0;
	if (s_name != NULL) {
		str_len = strlen(s_name);
		//t_simparams.m_pStaticFileName = new char[str_len];
		strcpy(t_simparams.m_pStaticFileName, s_name);
	}

	double *db_gen;

	long long size_of_sample = 3 * t_simparams.m_SizeX * t_simparams.m_SizeY * t_simparams.m_SizeZ; // 3 for the three components of the magnetization
	// allocate the buffer for static file and for pipe FILE I/O operataions.
	db_gen = new double[size_of_sample];
	// Loading the profile of magnetization of the ground state and extracting all possible values of the magnetization of saturation
	GetMagnetizationFromFile(s_name,
								db_gen,
								size_of_sample);
	
	//t_simparams.m_pMs = new double[MAX_MS];

	t_simparams.m_MsCount = GuessMsFromBuffer(db_gen, 
												size_of_sample, 
												t_simparams.m_pMs);

	t_simparams.m_MsMax = GetMaximumMsFromMsBuffer(t_simparams.m_pMs,
													t_simparams.m_MsCount);
	t_mag->SetSimulationParameters(&t_simparams);
	delete[] db_gen;
	return 0;
}

long long cReader::LoadOMFData(char* s_name, char **names, long long num_files, cMagnetization *t_mag, EXMETHOD* procc_method)
{	
	double *db_gen;
	double *db_stc;

	long long size_of_sample = (long long)3 * (long long)t_mag->s_params.m_SizeX * (long long)t_mag->s_params.m_SizeY * (long long)t_mag->s_params.m_SizeZ; // 3 for the three components of the magnetization
	long long r_len = (long long)size_of_sample/(long long)3; // reduction from 3 component m(r,t) vector to 1 component only;
	long long r_len_cmpx = (long long)2 * (long long)r_len;   // assuming that final buffer will have complex (2 component) format
	long long offset_xyz = (long long)r_len_cmpx * (long long)sizeof(float); // the size in bytes of the XYZ data in XYZT array.

	// allocate the buffer for static file and for pipe FILE I/O operataions.
	db_gen = new double[size_of_sample];
	db_stc = new double[size_of_sample];

	// Loading the profile of magnetization of the ground state and extracting all possible values of the magnetization of saturation
	GetMagnetizationFromFile(s_name,
								db_stc,
								size_of_sample);
	
	for (long long k=0;k<num_files;k++)
	{
		// Grub the data from the file
		GetMagnetizationFromFile(names[k],db_gen, size_of_sample);
		// Make some preprocessing
		ProcessTheDataInTheBuffers(db_stc,db_gen,size_of_sample, procc_method, &t_mag->s_params);	
		// [NO IMPLEMENTED]: extract only 2D array of data of user-defined plane
		Get2DMagFrom3DMag();
		// get addres of the global magnetization buffer for this particular time step
		long long off = r_len * (long long)k;
		long long  validator = GetMagnetizationComponent(db_gen, db_stc, (float*) &t_mag->data[off].Re, &t_mag->s_params, procc_method);
		if (validator != r_len_cmpx) return 1;	
	}
	
	// Copy the static data to the target cMagnetization class

	for (long long i=0;i<size_of_sample;i++)
	{
		t_mag->static_data[i] = (float)db_stc[i];
	}	
	t_mag->m_IsLoaded = 1;
	delete[] db_gen;
	delete[] db_stc;
	return 0;
}

long long cReader::GetSimulationsParameters(char *name, SIMPARAMS* sim_params)
{
	//long long buff_len = 256;
//  header marks

	char* hOOMMF = "OOMMF";
	char* hOVF = "OVF";
	char* hDataBeg8 = "# BEGIN: DATA BINARY 8\n";
	char* hDataBeg4 = "# BEGIN: DATA BINARY 4\n";
	char* hDesk = "DESC";
	char* hMIF = "MIF SOURCE FILE";
	char* hSST = "STAGE SIMULATION TIME";
	char* hTST = "TOTAL SIMULATION TIME";

	char* hXNS = "XNODES";
	char* hYNS = "YNODES";
	char* hZNS = "ZNODES";

	char* hXSS = "XSTEPSIZE";
	char* hYSS = "YSTEPSIZE";
	char* hZSS = "ZSTEPSIZE";

//  some default values of fields
	double t_timestep = 1.0;
	double t_totaltime = 1.0;
	double t_cs_x = 1.0;
	double t_cs_y = 1.0;
	double t_cs_z = 1.0;
	
	long long t_cc_x = 1;
	long long t_cc_y = 1;
	long long t_cc_z = 1;

	char t_miffilename[BUFF_LEN];//"undefined\n"};


	FILE *sim_file;
	errno_t error = fopen_s(&sim_file, name, "r+");
	if (error != 0) return 1;
	fseek( sim_file, 0L, SEEK_SET );
// proceeding to the simulations parameters extraction!
// STARTS HERE
	char t_s[BUFF_LEN];
	char tt_s[BUFF_LEN];
	char ttt_s[BUFF_LEN];
	float t_d=0.0;
//check if the file has actual OVF 2.0 format
	fscanf(sim_file, "%s %s %s %f", ttt_s, t_s, tt_s, &t_d);
	cCommonFunc::pCharToUpperInplace(t_s);
	cCommonFunc::pCharToUpperInplace(tt_s);
	if (strcmp(t_s,hOOMMF)!=0 || strcmp(tt_s,hOVF)!=0 || t_d!=2.0 )
	{
		// error: fake omf file without "OOMMF" signature
		// error: fake omf file without "OVF" signature
		// error: OVF file has version whitch is differ from 2.0
		fclose(sim_file);	
		return 1; 
	}
//read corresponding fields
	fgets(t_s,BUFF_LEN,sim_file);
	char seps[]   = ": \t\n";
	char seps_sc[] = ":\t\n";
	char seps_ws[] =" \t\n";
	while (!feof(sim_file))
	{
		fgets(t_s,BUFF_LEN,sim_file);
		cCommonFunc::pCharToUpperInplace(t_s);
		if (strcmp(t_s, hDataBeg4) == 0) break;
		if (strcmp(t_s, hDataBeg8) == 0) break;
		char* ts;
		ts = strtok(t_s,seps);
		cCommonFunc::pCharToUpperInplace(ts);
		if (strcmp(ts,"#")!=0)
		{
			// error: error in OVF header
			fclose(sim_file);	
			return 1;
		}
		while (ts != NULL)
		{
			ts = strtok(NULL, seps);
			if (ts == NULL) break;
			if (ts != NULL) cCommonFunc::pCharToUpperInplace(ts);
// CHECKING ALL POSSIBLE HEADER VALUES AND EXTRACTING THE DATA (THE DATA ALIGNED IN EXPECTIBLE ORDER)

			// process fields marked by # DESK
			if (strcmp(ts,hDesk)==0)
			{
				// MIF FILE NAME FIELD
				ts = strtok(NULL,seps_sc);
				cCommonFunc::pRemoveSpacesInTheBegining(ts);
				if (ts != NULL) cCommonFunc::pCharToUpperInplace(ts);
				if (strcmp(ts,hMIF)==0)
				{
					char* tempc = strtok(NULL, seps_ws);
					strcpy(t_miffilename, tempc);
					cCommonFunc::pRemoveSpacesInTheBegining(t_miffilename);
					long long str_len = 0;
					str_len = strlen(t_miffilename);
					//sim_params->m_pMIFFileName = new char[str_len];
					strcpy(sim_params->m_pMIFFileName, t_miffilename);
					break;
				}

				// STAGE SIMULATION TIME
				if (strcmp(ts,hSST)==0)
				{
					ts = strtok(NULL, seps);
					t_timestep = atof(ts);
					break;
				}

				// TOTAL SIMULATION TIME
				if (strcmp(ts,hTST)==0)
				{
					ts = strtok(NULL, seps);
					t_totaltime = atof(ts);
					break;
				}

			}
			// PROBING XNODES
			if (strcmp(ts,hXNS)==0)
			{
				ts = strtok(NULL, seps);
				t_cc_x = atoi(ts);
				break;
			}
			// PROBING YNODES
			if (strcmp(ts,hYNS)==0)
			{
				ts = strtok(NULL, seps);
				t_cc_y = atoi(ts);
				break;
			}
			// PROBING ZNODES
			if (strcmp(ts,hZNS)==0)
			{
				ts = strtok(NULL, seps);
				t_cc_z = atoi(ts);
				break;
			}
			
			// PROBING XSTEPSIZE
			if (strcmp(ts,hXSS)==0)
			{
				ts = strtok(NULL, seps);
				t_cs_x = atof(ts);
				break;
			}
			// PROBING YSTEPSIZE
			if (strcmp(ts,hYSS)==0)
			{
				ts = strtok(NULL, seps);
				t_cs_y = atof(ts);
				break;
			}
			// PROBING ZSTEPSIZE
			if (strcmp(ts,hZSS)==0)
			{
				ts = strtok(NULL, seps);
				t_cs_z = atof(ts);
				break;
			}

			break;
			
		}

	}

	sim_params->m_CellSizeX = t_cs_x;
	sim_params->m_CellSizeY = t_cs_y;
	sim_params->m_CellSizeZ = t_cs_z;

	sim_params->m_SizeX = t_cc_x;
	sim_params->m_SizeY = t_cc_y;
	sim_params->m_SizeZ = t_cc_z;

	sim_params->m_StageTime = t_timestep;
	sim_params->m_SimulationsTotalTime = t_totaltime;

	sim_params->m_MaxFrequency = 0.5 / t_timestep;
	sim_params->m_MaxInverseWavelengthX = 0.5 / t_cs_x;
	sim_params->m_MaxInverseWavelengthY = 0.5 / t_cs_y;
	sim_params->m_MaxInverseWavelengthZ = 0.5 / t_cs_z;

	sim_params->m_ResFrequency = sim_params->m_MaxFrequency / (0.5 * sim_params->m_NumberOfTimeSteps);
	sim_params->m_ResInverseWavelengthX = sim_params->m_MaxInverseWavelengthX / (0.5 * t_cc_x);
	sim_params->m_ResInverseWavelengthY = sim_params->m_MaxInverseWavelengthY / (0.5 * t_cc_y);
	sim_params->m_ResInverseWavelengthZ = sim_params->m_MaxInverseWavelengthZ / (0.5 * t_cc_z);
// END
	fclose(sim_file);	
	return 0;
}

long long cReader::GetMagnetizationFromFile(char *name, double* buffer, long long len)
{	
	char* hDataBeg8 = "# BEGIN: DATA BINARY 8\n";
	char* hDataBeg4 = "# BEGIN: DATA BINARY 4\n";	
	float* buffer4;

	char t_s[BUFF_LEN];
	FILE* mag_file;
	mag_file = fopen( name, "rb");
	int format = 1; // 0 - 4 bytes, 1 - 8 bytes

	//if (error != 0) return 1;
	fseek( mag_file, 0L, SEEK_SET );
	// NOW WE WILL TRY TO REACH THE DATA BEGINING
	while (!feof(mag_file))
	{
		fgets(t_s,BUFF_LEN,mag_file);
		cCommonFunc::pCharToUpperInplace(t_s);
		if (strcmp(t_s, hDataBeg8) == 0) break;
		if (strcmp(t_s, hDataBeg4) == 0) 
		{
			format = 0;
			break;
		}

	}
	double validator = 0.0;
	float validator4  = 0.0F;
	long long val_len = 0;
	switch (format)
	{
	case 0:
		buffer4 = new float[len];
		fread(&validator4,sizeof(float),1,mag_file);
		if (validator4 != 1234567.0) 
		{
			// error: OVF FILE DID NOT PASS THE VALIDATION
			fclose(mag_file);
			return 1;
		}
		val_len = fread((void *)buffer4, sizeof(float), len ,mag_file);
		if (val_len != len)
		{
			fclose(mag_file);
			return 1;
		}
		fclose(mag_file);
		for (long long i = 0; i < len; i++)
		{
			buffer[i] = (double)buffer4[i];
		}
		delete[] buffer4;
	case 1:
		fread(&validator,sizeof(double),1,mag_file);
		if (validator != 123456789012345.0) 
		{
			// error: OVF FILE DID NOT PASS THE VALIDATION
			fclose(mag_file);
			return 1;
		}
		val_len = fread((void *)buffer, sizeof(double), len ,mag_file);
		if (val_len != len)
		{
			fclose(mag_file);
			return 1;
		}
		fclose(mag_file);
	break;
	}
	return 0;


}
long long cReader::GuessMsFromBuffer(double *buffer, long long len, double *Ms)
{
	// NOTE: Rounding error is significant

	double t_Ms[MAX_MS];
	long long ii = 0;
	double tre_diff = MS_RERROR;
	for (long long i = 0; i<len; i+=3)
	{
		double m_s = sqrt(buffer[i]*buffer[i] + buffer[i+1]*buffer[i+1] + buffer[i+2]*buffer[i+2]);
		if (m_s == 0.0) continue;
		bool is_exist = false;
		for (long long j=0;j<ii;j++)
		{
			double diff = 0.0;
			if (t_Ms[j] != 0.0) double diff = abs(m_s-t_Ms[j])/t_Ms[j];
			if (diff < tre_diff) is_exist = true;

		}
		if (!is_exist)
		{
			t_Ms[ii] = m_s;

			if (ii  < MAX_MS) ii++;
		}
	}
	long long size = ii;
	//Ms = new double[size];//(double*)calloc(size, sizeof(double));
	for (long long i=0; i<size;i++)
	{
		Ms[i] = t_Ms[i];
	}

	return size;
}
double cReader::GetMaximumMsFromMsBuffer(double *b_Ms, long long len)
{
	if (len==1) return b_Ms[0];
	double max = b_Ms[0];
	for (long long i = 1; i< len;i++)
	{
		double t_v = b_Ms[i];
		if (t_v > max) max = t_v;
	}
	return max;
}
long long cReader::ProcessTheDataInTheBuffers(double *i_static, double *io_dynamic, long long len, EXMETHOD* proc_method, SIMPARAMS* sim_params)
{
	if (i_static==NULL || io_dynamic==NULL || proc_method==NULL || sim_params == NULL) return 1;
	
	if (proc_method->m_PreprocessingMethod == 1)
	{	
		//Should be optimized!
		//Buffer should be padded to the 128 bit boundary
		double norm = 1.0;
		if (proc_method->m_IsNormaliseByMs==1)
		{
			norm = 1.0 / sim_params->m_MsMax;
		}
		for (long long i=0;i<len;i++)
		{	
			io_dynamic[i] = norm * (io_dynamic[i] - i_static[i]);
		}
	}

	return 0;
}
long long cReader::Get2DMagFrom3DMag()
{
	return 0;
}
long long cReader::GetMagnetizationComponent(double *i_dynamic, double *i_static, float *o_dynamic, SIMPARAMS* sim_params, EXMETHOD* proc_method)
{
	//long long r_len = len / 3;
	double PI = 4.0 * atan(1.0);
	double i4PI = 1.0/(4.0 * PI);
	long long sx = sim_params->m_SizeX;
	long long sy = sim_params->m_SizeY;
	long long sz = sim_params->m_SizeZ;

	long long len = 3LL * sx * sy * sz;
	long long ii=0;
	switch(proc_method->m_MagnetizationComponent)
	{
	case 0://mx
		ii=0;
		for (long long i=0;i<len;i+=3)
		{
			o_dynamic[ii] = (float)i_dynamic[i]; // fill real part 
			o_dynamic[ii+1] = 0.0;		  // fill imaginary part
			ii+=2;
		}
		break;
	case 1://my
		ii=0;
		for (long long i=1;i<len;i+=3)
		{
			o_dynamic[ii] = (float)i_dynamic[i]; // fill real part 
			o_dynamic[ii+1] = 0.0;		  // fill imaginary part
			ii+=2;
		}
		break;
	case 2://mz
		ii=0;
		for (long long i=2;i<len;i+=3)
		{
			o_dynamic[ii] = (float)i_dynamic[i]; // fill real part 
			o_dynamic[ii+1] = 0.0;		  // fill imaginary part
			ii+=2;
		}
		break;
	case 3://minp
		// NOTE: NOT YET IMPLEMENTED !!!
		ii=0;
		for (long long i=0;i<len;i+=3)
		{

			double mx = i_dynamic[i];
			double my = i_dynamic[i+1];
			double mz = i_dynamic[i+2];
			o_dynamic[ii] = 0.0; // fill real part 
			o_dynamic[ii+1] = 0.0;		  // fill imaginary part
		}
	case 4: // get magnetic charges, the purpose supposed to be non-disclosed by NDA.
		// here is naive code
		for (long long k=0; k < sz; k++)
		{
			long long km2 = k - 2;
			long long km1 = k - 1;
			long long k1 = k + 1;
			long long k2 = k + 2;
			for (long long j=0; j < sy; j++)
			{
				long long jm2 = j - 2;
				long long jm1 = j - 1;
				long long j1 = j + 1;
				long long j2 = j + 2;
				for (long long i=0; i < sx; i++)
				{
					long long im2 = i - 2;
					long long im1 = i - 1;
					long long i1 = i + 1;
					long long i2 = i + 2;

					double div = 0.0;

					double yim2 = (im2 >= 0)?i_dynamic[p_addr_xyz_v3(sx, sy, im2, j, k)]:0.0;
					double yim1 = (im1 >= 0)?i_dynamic[p_addr_xyz_v3(sx, sy, im1, j, k)]:0.0;
					double yi1 = (i1 < sx)?i_dynamic[p_addr_xyz_v3(sx, sy, i1, j, k)]:0.0;
					double yi2 = (i2 < sx)?i_dynamic[p_addr_xyz_v3(sx, sy, i2, j, k)]:0.0;
					
					div += df_dxi(sim_params->m_CellSizeX, yim2, yim1, yi1, yi2);

					double yjm2 = (jm2 >= 0)?i_dynamic[p_addr_xyz_v3(sx, sy, i, jm2, k)+1]:0.0;
					double yjm1 = (jm1 >= 0)?i_dynamic[p_addr_xyz_v3(sx, sy, i, jm1, k)+1]:0.0;
					double yj1 = (j1 < sy)?i_dynamic[p_addr_xyz_v3(sx, sy, i, j1, k)+1]:0.0;
					double yj2 = (j2 < sy)?i_dynamic[p_addr_xyz_v3(sx, sy, i, j2, k)+1]:0.0;
					
					div += df_dxi(sim_params->m_CellSizeY, yjm2, yjm1, yj1, yj2);

					double ykm2 = (km2 >= 0)?i_dynamic[p_addr_xyz_v3(sx, sy, i, j, km2)+2]:0.0;
					double ykm1 = (km1 >= 0)?i_dynamic[p_addr_xyz_v3(sx, sy, i, j, km1)+2]:0.0;
					double yk1 = (k1 < sz)?i_dynamic[p_addr_xyz_v3(sx, sy, i, j, k1)+2]:0.0;
					double yk2 = (k2 < sz)?i_dynamic[p_addr_xyz_v3(sx, sy, i, j, k2)+2]:0.0;
					
					div += df_dxi(sim_params->m_CellSizeZ, ykm2, ykm1, yk1, yk2);

					long long waddr = p_addr_xyz_v2(sx, sy, i, j , k);

					o_dynamic[waddr] = div * i4PI;
					o_dynamic[waddr + 1] = 0.0;

				}
			}
		}
		ii = 2 * sx * sy * sz;
		break;
	}

	return ii;
}
#pragma managed