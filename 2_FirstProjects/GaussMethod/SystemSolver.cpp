#include <iostream>
#include "gauss_tools.h"
using namespace std;

//Реализация метода Гаусса
bool gauss_solve(double** A, double* &x, double* b, int n)
{
    x = new double[n];
    //Прямой ход метода Гаусса
    for (int j = 0; j < n; j++)
    {
        double alpha;

        //Переместим строку с макс. j-м
        //элементом на позицию j
        int maxJ = j;
        for (int i = j + 1; i < n; i++)
        {
            if (abs(A[maxJ][j]) < abs(A[i][j]))
                maxJ = i;
        }
        if (j != maxJ) {
            swap(A[j], A[maxJ]);
            swap(b[j], b[maxJ]);
            cout << "> Смена строк "
                << j << " и " << maxJ << '\n';
            if(n <= 10)
                print_system(A, b, n);
            cout << "\n\n";
        }
        if (A[maxJ][j] == 0) {
            cout << "Система несовместна.\n";
            return false;
        }//

        for (int i = j + 1; i < n; i++)
        {
            alpha = A[i][j] / A[j][j];
            for (int k = j; k < n; k++)
            {
                A[i][k] -= alpha * A[j][k];
            }
            b[i] -= alpha * b[j];
        }
        cout << "> Прямой ход " << j + 1 << ":\n";
        if (n <= 10)
            print_system(A, b, n);
        cout << "\n\n";
    }

    //Обратный ход метода Гаусса
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
            sum += A[i][j] * x[j];

        x[i] = (b[i] - sum) / A[i][i];
    }
    return true;
}

//Проверка решения уравнения
double error_check(double** A, double* x, double* b, int n)
{
    double err = 0.0, str_sum;
    for (int i = 0; i < n; i++)
    {
        str_sum = 0.0;
        for (int j = 0; j < n; j++)
            str_sum += A[i][j] * x[j];
        
        double diff = abs(str_sum - b[i]);
        if (diff > err)
            err = diff;
    }
    return err;
}