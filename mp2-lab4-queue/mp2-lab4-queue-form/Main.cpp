#include "QueueForm.h"
#include <Windows.h> 
using namespace mp2lab4queueform;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew QueueForm);
	return 0;
}