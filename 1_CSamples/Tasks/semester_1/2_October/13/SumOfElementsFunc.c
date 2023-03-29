#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
4. Вычислить сумму всех элементов массива (создать для этого отдельную функцию)
*/
int sum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int arr[] = {1, 2, 3, 4, 5, 6};
    int s = sum(arr, 6);
    printf("%i", s);
}