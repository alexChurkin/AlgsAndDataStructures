#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
using namespace std;
/*
1. Классы. Введение в необходимость их использования
*/

struct complex {
    double re, im;
};

//Суммирование вне функции; ! создание нового числа
complex sum_1(complex a, complex b) {
    complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

//Суммирование вне функции; ! без создания нового числа
void sum_2(complex &a, complex b) {
    a.re += b.re;
    a.im += b.im;
}
//Но такой подход имеет свои минусы, т.к. эти функции находятся отдельно
//от класса

int main()
{
    setlocale(LC_ALL, "russian");
    cout << "hey";
    
    return 0;
}