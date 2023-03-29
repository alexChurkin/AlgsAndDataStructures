#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
5. Вывести все элементы массива на экран (создать отделную функцию)
*/
void print_array(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("%i]\n", arr[size - 1]);
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(arr, 10);
}