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

//Замена с использованием запоминания временной строки (способ 1)
void cyclic_matrix_replacement_1(double **matrix, int n, int m)
{
    //Создадим временный массив, в который запишем последнюю строчку
    double *t_str = new double[n];
    //Запишем последнюю строчку
    for (int j = 0; j < m; j++)
        t_str[j] = matrix[n - 1][j];

    //Теперь с (n-2)-й (предпоследней) строки будем копировать (снизу вверх)
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j < m; j++)
        {
            matrix[i+1][j] = matrix[i][j];
        }
    //Теперь запишем в верхнюю строчку  нашу t_str
    for(int j = 0; j < m; j++) {
        matrix[0][j] = t_str[j];
    }
    delete[] t_str;
}

//Замена с использованием указателей и без дополнительной памяти 
//(способ 2)
void cyclic_matrix_replacement_2(double **matrix, int n, int m)
{
    //Запомним указатель на (n-1)-ю (последнюю) строчку
    double* t = matrix[n-1];

    //Теперь с (n-2)-й (предпоследней) строки будем копировать (снизу вверх)
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j < m; j++)
            swap(matrix[i + 1], matrix[i]);
    //Теперь запишем в верхний (указатель на первую строку)
    //Указатель на последнюю
    matrix[0] = t;
}

//Матрица n x m
int main()
{
    setlocale(LC_ALL, "russian");
    int n = 4, m = 3;
    double **matr = make_matrix(n, m);
    fill_matrix(matr, n, m);

    cyclic_matrix_replacement_2(matr, n, m);
    cout << "Новая матрица:\n";
    print_matrix(matr, n, m);
    return 0;
}