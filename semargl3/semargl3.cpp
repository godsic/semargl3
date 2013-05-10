// semargl3.cpp : main project file.

#include "Form1.h"

using namespace semargl3;
using namespace System::IO;
using namespace System;
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	//array<String^>^ args = Environment::GetCommandLineArgs();

	long long rank = args->GetLongLength(0);
	if (rank > 0)
	{
		//do work
		Console::WriteLine("semargl3 batch mode.");
		mcSettings::ProcessCommands(args);
		long long error = 0;
		if (mcSettings::m_dpFilesCount > 0) error = mcSample::DoBatch(); 
		if (error == 0) Console::WriteLine("Finished.");
		else Console::WriteLine("ERROR!!!");
	}
	else
	{
		Application::Run(gcnew Form1());
	}
	return 0;
}
