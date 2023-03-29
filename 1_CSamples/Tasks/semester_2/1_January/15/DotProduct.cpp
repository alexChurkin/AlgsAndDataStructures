#include <iostream>
#include <locale.h>
using namespace std;

double dot_product(double a[], double b[], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
        result += a[i] * b[i];
    return result;
}

//3. Скалярное произведение матрицы на вектор
double *matrix_on_vector(double **matr, double *vect, double size)
{
    double *result = new double[size];

    for (int i = 0; i < size; i++)
        result[i] = dot_product(matr[i], vect, size);

    return result;
}

int main()
{
    setlocale(LC_ALL, "russian");
    double matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double vect[3] = {4, 5, 6};

    //double* result = matrix_on_vector(matrix, vect, 3);
    //for (int i = 0; i < 3; i++)
    //{

    //}
    return 0;
}