#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <cstring>
using namespace std;

//Хранит информацию об ошибке для её дальнейшей обработки
class Exception
{
private:
	char* file; //Имя файла
	char* func; //Имя функции
	int line;   //Номер строки
	char* desc; //Подробное описание

public:
	Exception(const char* _file, const char* _func, int _line, const char* _desc);
	Exception(const Exception& e);
	~Exception();

	void print() const;
	friend ostream& operator<<(ostream& os, const Exception& e);
};