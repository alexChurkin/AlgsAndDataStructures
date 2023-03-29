#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;

//Неверный вариант
void swapWrong(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//Правильно в C++ (параметр a будет передан по ссылке)
//Внутри самой функции дополнительные обозначения не нужны!
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    setlocale(LC_ALL, "russian");
    int a = 6, b = 3, &i = a;
    cout << "a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << ". b = " << b << endl;
    i = 100;
    cout << "i = " << i << endl;
    cout << "a = " << a << endl;
    return 0;
}