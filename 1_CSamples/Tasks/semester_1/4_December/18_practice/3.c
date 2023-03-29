#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

#define SIZE 4

/*
3. Задача. Дана квадратная матрица размера N × N. Найти суммы элементов всех ее нечетных строк.
*/

//i - строка, j - столбец; нумерация столбцов с 1
void main()
{
    setlocale(LC_CTYPE, "rus");
    int matrix[SIZE][SIZE];

    printf("Введите матрицу %ix%i:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%i", &matrix[i][j]);

    for (int i = 0; i < SIZE; i += 2)
    {
        int sum = 0;
        for (int j = 0; j < SIZE; j++)
            sum += matrix[i][j];
        printf("%i ", sum);
    }
}