#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;

void print_matrix(double **matrix, int m, int n)
{
    cout << "Матрица:\n";
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

    if (count <= 9)
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

void destroy_matrix(double **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
        delete[] matrix[i];
    delete[] matrix;
}
/* .................................................. */

//Транспонирование квадратной матрицы
void transpose_square(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
}

//Транспонирование любой матрицы в новый массив
double **transpose_into_new(double **matrix, int m, int n)
{
    double **result = make_matrix(n, m);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            result[j][i] = matrix[i][j];
    return result;
}

int main()
{
    setlocale(LC_ALL, "russian");

    int m = 2, n = 3;
    double **matr = make_matrix(m, n);
    fill_matrix(matr, m, n);

    cout << "\n>Транспонируем матрицу в новую:\n";
    double **newmatr = transpose_into_new(matr, m, n);
    print_matrix(newmatr, n, m);

    if (m == n)
    {
        cout << ">Транспонируем матрицу как квадратную:\n";
        transpose_square(matr, m);
        print_matrix(matr, m, n);
    }

    destroy_matrix(matr, m, n);
    destroy_matrix(newmatr, n, m);
    return 0;
}