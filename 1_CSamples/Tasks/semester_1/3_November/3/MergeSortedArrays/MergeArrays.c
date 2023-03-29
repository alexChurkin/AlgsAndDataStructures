#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include "helper.h"

/*
4. Слияние 2-х отсортированных массивов
*/
int *merge_arrays(int arr1[], int size1, int arr2[], int size2)
{
    int startPos = 0;

    int *final_arr = create_empty_array(size1 + size2);

    //i - счётчик в массиве 1, j - в массиве 2,
    //k - в финальном
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        //Если элемент в массиве 1 меньше, то ставим его
        if (arr1[i] < arr2[j])
            final_arr[k++] = arr1[i++];
        //Иначе ставим тот элемент, который меньше (т.е. из массива 2)
        else
            final_arr[k++] = arr2[j++];
    }

    //Добавляем оставшиеся элементы (сработает только один из двух while-ов)
    while (i < size1)
        final_arr[k++] = arr1[i++];
    while (j < size2)
        final_arr[k++] = arr2[j++];
    return final_arr;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    int size1;
    int *array1 = get_array(&size1, 1);
    int size2;
    int *array2 = get_array(&size2, 2);
    /*int array2[] = {1, 2, 3, 4, 5};
    int size2 = 5;
    int array1[] = {5, 6, 7, 8, 9, 10};
    int size1 = 6;*/
    int *final_arr = merge_arrays(array1, size1, array2, size2);
    free(array1);
    free(array2);
    printf("\nРезультат:\n");
    print_array(final_arr, size1 + size2);
}