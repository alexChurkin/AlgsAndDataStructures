#include "pch.h"
#include "CppUnitTest.h"
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Log(string str) {
	Logger::WriteMessage(str.c_str());
}

void LogLine(string str) {
	Log(str + "\n");
}