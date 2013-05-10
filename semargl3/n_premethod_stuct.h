#ifndef _N_PREMETHOD_STRUCT
#define _N_PREMETHOD_STRUCT

// Defines the structure which determs the behaviour of the data extracting proces
// MAD
// 2010
#pragma unmanaged

// This structure describes the methos of the data pre- and post- processing
struct EXMETHOD
{
	public: long long m_MagnetizationComponent; // Describes which particular component of the magnetiation to extract(0-mx, 1-my, 2-mz, 3-minp)
	public: long long m_PreprocessingMethod;// Describes preprocessing method (0 - without preprocessing, 1 - substrute the static magnetization)
	public: long long m_IsNormaliseByMs;// Describes whenevere the data should or should not be normalized by the magnetization of saturation value (0 - without normaliation, 1 - normalize the data by the magnetization of saturation)
};

#pragma managed

#endif	