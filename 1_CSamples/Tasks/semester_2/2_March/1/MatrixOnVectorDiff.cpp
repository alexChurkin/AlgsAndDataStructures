#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;

void print_matrix(double **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        int j;
        for (j = 0; j < n - 1; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << matrix[i][j] << '\n';
    }
}

double **make_matrix(int m, int n)
{
    double **matrix = new double *[m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];
    return matrix;
}

void fill_matrix(double **matrix, int m, int n)
{
    int count = m * n;

    if (count <= 12)
    {
        cout << "Введите " << m * n << " элементов матрицы:\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        return;
    }

    cout << "Матрица будет заполена автоматически.\n";
    srand((unsigned int)time(NULL));
    int range_min, range_max;
    cout << "Введите минимальное значение: \n";
    cin >> range_min;
    cout << "Введите максимальное значение: \n";
    cin >> range_max;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] =
                (int)((double)rand() / (RAND_MAX + 1) * (range_max + 1 - range_min) +
                      range_min);
        }
    }
    cout << "Успешно создана матрица: \n";
    print_matrix(matrix, m, n);
}

//Вернёт ошибку
double error_check(double **A, int n, double *X, double *B)
{
    double err = 0.0, str_sum;
    for (int i = 0; i < n; i++)
    {
        str_sum = 0.0;
        for (int j = 0; j < n; j++)
            str_sum += A[i][j] * X[i];

        if (abs(str_sum - B[i] > err))
            err = abs(str_sum - B[i]);
    }
    return err;
}
//Матрица n x m
int main()
{
    setlocale(LC_ALL, "russian");
    int n = 4, m = 3;
    double **matr = make_matrix(n, m);
    fill_matrix(matr, n, m);

    cout << "Новая матрица:\n";
    print_matrix(matr, n, m);
    return 0;
}