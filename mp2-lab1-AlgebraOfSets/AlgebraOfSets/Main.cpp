#include "AOSForm.h"
#include <Windows.h> 
using namespace AlgebraOfSets;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew AOSForm);
	return 0;
}