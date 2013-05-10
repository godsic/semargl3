#pragma once

public class mcImage
{
public:
	mcImage(void);
	static void GenerateSampleProfileImage();
	static void DrawRectProbeXY();
	static void DrawRectProbeXZ();
	static void DrawRectProbeYZ();
							
	static void DrawProbe();
	static void Draw2DTRS();
	static void Draw2DFRS();
	static void Draw2DMagRe();
	static void Draw2DMagImg();
	static void Draw2DDispersionSlice();

	static void SaveImage(System::Drawing::Bitmap^ img);
};
