#ifndef _N_PROBE_H
#define _N_PROBE_H

#pragma unmanaged


class cProbe
{

public: static long long ProbeType;
public:	static long long X0;
public:	static long long Y0;
public:	static long long Z0;

public:	static long long X1;
public:	static long long Y1;
public:	static long long Z1; 

public:	static double X0_m;
public:	static double Y0_m;
public:	static double Z0_m;

public:	static double X1_m;
public:	static double Y1_m;
public:	static double Z1_m; 

public: static long long sizeX;
public: static long long sizeY;
public: static long long sizeZ;

public: static double sizeX_m;
public: static double sizeY_m;
public: static double sizeZ_m;

public: static double m_multResInverseWavelengthX;
public: static double m_multResInverseWavelengthY;
public: static double m_multResInverseWavelengthZ;

public: static double m_skindepthX;
public: static double m_skindepthY;
public: static double m_skindepthZ;

public: static float* probe;

public:	static long long isCreated;
public: static void Reset();
public: static void Create(long long fsizeX, long long fsizeY, long long fsizeZ, double csx, double csy, double csz);

	
};

#pragma managed

#endif