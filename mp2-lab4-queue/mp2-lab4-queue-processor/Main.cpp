#include "ProcessorForm.h"
#include <Windows.h>
using namespace mp2lab4queueprocessor;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ProcessorForm);
	return 0;
}