#include <iostream>
#include <locale.h>
using namespace std;


//2. Работа с динамической памятью
int main()
{
    setlocale(LC_ALL, "russian");

    int n = 10;
    int m = 10;

    double **p = new double *[n];
    for (int i = 0; i < n; i++)
        p[i] = new double[m];

    //Then we are doing something...
    //And just deleting every array before deleting p
    for (int i = 0; i < n; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}