#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <cstring>
#include "Exception.h"
using namespace std;

Exception::Exception(const char* _file, const char* _func, int _line, const char* _desc)
{
	int n1 = strlen(_file);
	file = new char[n1 + 1];
	strcpy(file, _file);

	int n2 = strlen(_func);
	func = new char[n2 + 1];
	strcpy(func, _func);

	int n3 = strlen(_desc);
	desc = new char[n3 + 1];
	strcpy(desc, _desc);

	line = _line;
}

Exception::Exception(const Exception& e)
{
	int n1 = strlen(e.file);
	file = new char[n1 + 1];
	strcpy(file, e.file);

	int n2 = strlen(e.func);
	func = new char[n2 + 1];
	strcpy(func, e.func);

	int n3 = strlen(e.desc);
	desc = new char[n3 + 1];
	strcpy(desc, e.desc);

	line = e.line;
}

void Exception::print() const
{
	cout << "Файл: " << file << '\n';
	cout << "Функция: " << func << '\n';
	cout << "Номер строки: " << line << '\n';
	cout << "Подробнее: " << desc << '\n';
}

ostream& operator<<(ostream& os, const Exception& e)
{
	os << "Файл: " << e.file << '\n';
	os << "Функция: " << e.func << '\n';
	os << "Номер строки: " << e.line << '\n';
	os << "Подробнее: " << e.desc << '\n';
	return os;
}

Exception::~Exception()
{
	delete[] file;
	delete[] func;
	delete[] desc;
}