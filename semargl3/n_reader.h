#ifndef _N_READER_H
#define _N_READER_H

#pragma unmanaged

#include "n_mag_class.h"
#include "n_premethod_stuct.h"
#include "n_common_func.h" 
class cReader
{
public: static long long ProbeParametersOfSimulations(char* s_name, char **names, long long num_files, cMagnetization *t_mag);
public: static long long LoadOMFData(char* s_name, char** names, long long num_files, cMagnetization* t_mag, EXMETHOD* proc_method);
private: static long long GetSimulationsParameters(char* name, SIMPARAMS* sim_params);
private: static long long GetMagnetizationFromFile(char* name, double* buffer, long long len);
private: static long long GuessMsFromBuffer(double* buffer, long long len, double *Ms);				// The function returnes the number of different values of magnetization of saturations founded in the buffer, while the values are passed to Ms array
private: static double GetMaximumMsFromMsBuffer(double *b_Ms, long long len);					// The function returnes the maximum value of the magnatization of saturation in the buffer containing different magnetization of saturation 
private: static long long ProcessTheDataInTheBuffers(double *i_static, double *io_dynamic, long long len,  EXMETHOD* proc_method,SIMPARAMS* sim_params);   // In-place processing of data 
private: static long long Get2DMagFrom3DMag();												// Reduce the 3D data to 2D if requered
private: static long long GetMagnetizationComponent(double *i_dynamic, double *i_static, float *o_dynamic, SIMPARAMS* sim_params, EXMETHOD* proc_method); // Get user-defined dynamic magnetization component, len represent the actual length of i_dynamic array, function returns the length (in elements) of the reduced data 
};

#pragma managed

#endif