#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Функция вывода матрицы на экран
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

//Функция создания матрицы
double **make_matrix(int m, int n)
{
    double **matrix = new double *[m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];
    return matrix;
}

//Функция заполнения матрицы
void fill_matrix(double **matrix, int m, int n)
{
    int count = m * n;
    //Считываем с клавиатуры
    if (count <= 9)
    {
        cout << "Введите " << m * n << " элементов матрицы:\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        return;
    }

    //Генерируем случайно
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

void destroy_matrix(double **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main()
{
    setlocale(LC_ALL, "russian");

    int m = 5, n = 5;
    double **matr = make_matrix(m, n);
    fill_matrix(matr, m, n);
    destroy_matrix(matr, m, n);
    return 0;
}