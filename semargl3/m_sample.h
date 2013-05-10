#pragma once

using namespace System::Drawing;

public ref class mcSample
{
public:
	mcSample(void);
	// PROBE PAGE
	static System::Drawing::Bitmap^ sample_xy;
	static System::Drawing::Bitmap^ sample_xz;
	static System::Drawing::Bitmap^ sample_yz;

	// TRS PAGE
	static System::Drawing::Bitmap^ trs_image;
	static System::Drawing::Bitmap^ frs_image;

	static System::Drawing::Bitmap^ mag_re;
	static System::Drawing::Bitmap^ mag_img;
	static System::Drawing::Bitmap^ spectrum;
	static System::Drawing::Bitmap^ dispersion;

	static void LoadTheData();
	static void DoTRSandFRS();
	static void GenFFTWindow();
	static void SaveTRSToTextFile(System::String^ filename);
	static void SaveFRSToTextFile(System::String^ filename);
	static void DrawMagnetization();
	static void Save2DToTextFile(System::String^ filename, System::String^ header, long long mode);
	static void Save3DToTextFile(System::String^ filename, System::String^ header, long long mode);
	static void DoSpectrum();
	static void SaveSpectrumToTextFile(System::String^ filename);
	static void SaveSpectrumToTextFileN(char* cfilename);
	static void Do3DDispersion();
	static void GetSliceOf3DDispersion();
	static void DrawDispersionSlice();
	static void SaveDispersionToTextFile(System::String^ filename);
	static long long DoBatch();
	static void GetMultipoleExpansion(System::String^% text);

	static void Get3DMode();
	static void Delete3DMode();
	static void SaveProfilesBatch();
	static void GenerateTextForProfiles3D(System::String^% name, System::String^% header, long long graph);
	static void GetModeWaveVectors(System::String^% text);

	static void Clean();
};
