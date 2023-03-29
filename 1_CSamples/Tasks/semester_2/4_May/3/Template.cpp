#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
using namespace std;

/*
1. Пример использования шаблонов (универсальный swap)
*/
template <class T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    setlocale(LC_ALL, "russian");

    return 0;
}