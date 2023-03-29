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

//Поиск седловой точки матрицы и её вывод, если есть
void print_saddle_point(double **matrix, int m, int n)
{
    int i_res, j_res, value;

    //Найдём минимальный элемент в строке
    for (int i = 0; i < m; i++)
    {
        //Индекс минимального в строке
        int min_index = 0;

        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] < matrix[i][min_index])
                min_index = j;
        }
        double min_in_row = matrix[i][min_index];

        //Проверим, что это максимальный элемент в столбце j
        double max_in_column = matrix[0][min_index];
        for (int ii = 1; ii < n; ii++)
            if (matrix[ii][min_index] > max_in_column)
                max_in_column = matrix[ii][min_index];

        if (max_in_column == min_in_row)
        {
            i_res = i;
            j_res = min_index;
            value = matrix[i][min_index];
            cout << "Седловая точка найдена.\n";
            cout << "i = " << i_res << ", j = "
                 << j_res << ", значение " << value;
            return;
        }
    }
    cout << "Седловая точка не найдена";
}

int main()
{
    setlocale(LC_ALL, "russian");

    int m = 3, n = 3;
    double **matr = make_matrix(m, n);
    fill_matrix(matr, m, n);

    print_saddle_point(matr, m, n);

    destroy_matrix(matr, m, n);
    return 0;
}