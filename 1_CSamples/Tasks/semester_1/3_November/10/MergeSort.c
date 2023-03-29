#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

/*
1. Сортировка слиянием
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

void merge_two(int arr[], int l, int m, int r)
{
    int i = l,
        j = m + 1,
        t = 0;
    int *temp_arr;
    temp_arr = (int *)malloc((r - l + 1) * sizeof(int));

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp_arr[t] = arr[i], i++;
        }
        else
        {
            temp_arr[t] = arr[j], j++;
        }
        t++;
    }

    while (i <= m)
    {
        temp_arr[t] = arr[i];
        t++;
        i++;
    }
    while (j <= r)
    {
        temp_arr[t] = arr[j];
        t++;
        j++;
    }

    for (int i = l; i <= r; i++)
    {
        arr[i] = temp_arr[i - l];
    }
    free(temp_arr);
}

void merge_sort(int *arr, int l, int r)
{
    if (l == r)
        return;
    int c = (l + r) / 2;
    merge_sort(arr, l, c);
    merge_sort(arr, c + 1, r);
    merge_two(arr, l, c, r);
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int arr[] = {3, 6, 2, 6, 2, 7, 9, 1, 2, 5};
    //merge_two(arr, 0, 4, 8);
    merge_sort(arr, 0, 9);
    print_array(arr, 10);
}