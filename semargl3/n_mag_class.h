#ifndef _N_MAG_CLASS_H
#define _N_MAG_CLASS_H
#pragma unmanaged
#include "n_types.h"


//Describes the class containing all the data extracted from the simulations
class cMagnetization
{
	public: cMagnetization();		// Constructor of the cMagnetization class
	public: cMagnetization(SIMPARAMS* params);		// Constructor of the cMagnetization class
    public: ~cMagnetization();						// Destructor of the cMagnetization class


	public:	COMPLEX* data;							// Pointer to the array containing dynamic data
	public: float* static_data;						// Contains the spatial profile of the magnetization of the ground state
	public: SIMPARAMS s_params;						// Contains describtions (parameters) of the simulations
	public: long long m_SizeOfDataBytes;					// Size of the .data in bytes (useful) for memory footprint calculation
	public: long long m_SizeOfDataElements;				// Size of the data in the elements (double)
	public: long long m_IsLoaded;							// This flag indicates whenever the data is loaded or not
	public: long long m_IsFreqDomain;						// This flag indicates whenever the data represents in the frequency domain or not
	public: long long m_IsKDomain;						// This flag indicates whenever the data represents in the inverse wavelength domain or not
	public: long long m_IsAmpAndPhase;					// This flag indicates the representation of the complex data 
	public: long long m_IsParametersLoaded;				// This flag indicates whenever the simulations parameters has been loaded or not
	public: COMPLEX* avgdata;						// This arrays conains the averaged magnetization as a function of time
	public: long long m_asizeX;							// Defines the size of the averaged data along X
	public: long long m_asizeY;							// Defines the size of the averaged data along Y						
	public: long long m_asizeZ;							// Defines the size of the averaged data along Z	 
	public: long long m_asizeT;							// Defines the size of the averaged data along T
	public: COMPLEX* avgdata_fft;					// This arrays contains the FFT of the averaged magnetization as a function of time
	public: COMPLEX* layer_buff_2d;					// This buffer contains 2D layer extracted from the general 4D data
	public: COMPLEX* layer_buff_3d;					// This buffer contains 3D layer extracted from the general 4D data
	public: double k3d[3];							// This array contains the wavevector of the 3D mode.
	public: double n3d[3];							// This array contains the wave numbers of the 3D mode.
	public: long long m_lsizeX;							// Width of the 2D/3D layer buffer
	public: long long m_lsizeY;							// Height of the 2D/3D layer buffer
	public: long long m_lsizeZ;							// Width of the 3D layer buffer

	private: long long m_isXavg;							// Indicates that X direction has been averaged while generating the slice of the 4D dispersion
	private: long long m_isYavg;							// Indicates that Y direction has been averaged while generating the slice of the 4D dispersion
	private: long long m_isZavg;							// Indicates that Z direction has been averaged while generating the slice of the 4D dispersion


	public: long long ValidateRealData();
	public: long long ValidateCMPXData();

	public: void AllocateBuffers();
	private: void AllocateAvgBuffer(long long sizex, long long sizey, long long sizez, long long sizet); // Allocates the space for the averaged data
    private: void AllocateAvgFFTBuffer(long long sizex, long long sizey, long long sizez, long long sizet); // Allocates the space for the FFT of the averaged data
	private: void Allocate2DLayerBuffer(long long sizex, long long sizey); // Allocates the space for the 2D spatial profile buffer
	private: void Allocate3DLayerBuffer(long long sizex, long long sizey, long long sizez); // Allocates the space for the 3D spatial profile buffer
	public: void Destroy3DLayerBuffer();// free the memory of 3D layer buffer
	public: void CleanBuffers();

	public: void SetSimulationParameters(SIMPARAMS* sim_params);
	public: void dbgDoDataAveraging(); 
	
	public: void SetParametersFlag();
	public: void ResetParametersFlag();
	public: long long GetParametersFlag();
	public: void DoAmpPhsFrom();
	public: void DoAmpPhsFromParallel();
    public: void Do1DAveraging(long long axis);  // 0 - x, 1 - y, 2 - z
    public: void Do2DAveraging(long long plane); // 0 - yz, 1 - xz, 2 - xy
	public: void Do3DAveraging();			// PROPER AVERAGING <(x,y)> = (<x>, <y>)
    public: void Do3DAveragingBW(float kxa, float kxb, float kya, float kyb, float kza, float kzb);			// PROPER AVERAGING <(x,y)> = (<x>, <y>)

    public: void Do3DAveragingBWCMPX(float kxa, float kxb, float kya, float kyb, float kza, float kzb);			// PROPER AVERAGING <(x,y)> = (<x>, <y>)
	public: void Do3DAveragingBWCMPXParallel(float kxa, float kxb, float kya, float kyb, float kza, float kzb);			// PROPER AVERAGING <(x,y)> = (<x>, <y>)


	public: void Do3DAveragingAmp();		// Improper (but more informative) <Amp((x,y)> averaging, so the output is in the Amp; Phase format
	public: void Do3DAveragingAmpParallel();		// Improper (but more informative) <Amp((x,y)> averaging, so the output is in the Amp; Phase format

	public: void Do1DAveragingInplace(long long axis); // 0 - x, 1 - y, 2 - z PROPER AVERAGING <(x,y)> = (<x>, <y>)

	public: void Do1DAveragingInplaceParallel(long long axis); // 0 - x, 1 - y, 2 - z PROPER AVERAGING <(x,y)> = (<x>, <y>)

	public: void Do1DAveragingAmpInplace(long long axis); // 0 - x, 1 - y, 2 - z Improper (but more informative) <Amp((x,y)> averaging, so the output is in the Amp; Phase format

	public: void Get2DFFTFromAveragedData(); 

	// FFT
	public: void DoFFTT();
	public: void DoFFTTParallel();
	public: void DoFFTTMParallel();
	public: void DoShiftedFormT();

	public: void DoShiftedFormTParallel();
    public: void DoShiftedFormSpectrumParallel();


	public: void DoShiftedFormParallel();

	public: void DoFFTX();
	public: void DoFFTXParallel();
	public: void DoShiftedFormX();
	public: void DoShiftedFormXParallel();


	public: void DoFFTY();
	public: void DoFFTYParallel();
	public: void DoShiftedFormY();
	public: void DoShiftedFormYParallel();

	public: void DoFFTZ();
	public: void DoFFTZParallel();
	public: void DoShiftedFormZ();
	public: void DoShiftedFormZParallel();

	public: void DoF2A(long long avgmethod);
	public: void DoA2F();
    public: void DoFF2A();

	public: void Get2DSpatialLayer(long long plane, long long timestep, long long depth); // 0 - xy, 1 - xz, 2 - yz 
	public: void Get3DSpatialLayer(long long timestep); 
	public: void Get3DModeWaveNumber();


	public: void Get4DFFT();
	public:	void Do3DFFT();
	public:	void Do3DFFTParallel();
	public: void Get4DFFTVolumeSlice(long long isAvgX, long long isAvgY, long long isAvgZ, long long AvgMX, long long AvgMY, long long AvgMZ, long long coordx, long long coordy, long long coordz);
	private: void Get2Dfrom4DVolume(long long isavgx, long long isavgy, long long isavgz, long long coordx, long long coordy, long long coordz);

	private: void Get2Dfrom4DNAvg(long long fixedaxis, long long coordA, long long coordB);
	private: void Get2Dfrom4DSAvg(long long fixedaxis, long long avg, long long coordA);
	private: void Get2Dfrom4DDAvg(long long fixedaxis);
	private: void Get2Dfrom4DTAvg();
	
	// multipole expansion part
	public: void GetMultipoleCoeff(long long t, long long order, double** Q, long long** size);	
	private: void GetOrigin(long long t, double** r);
};

#pragma managed

#endif