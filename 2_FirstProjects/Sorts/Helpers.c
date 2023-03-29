#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

char* is_sorted(int arr[], int size)
{
	int i;
	for (i = 1; i < size; i++)
	{
		if (arr[i - 1] > arr[i])
			return "НЕТ!!!";
	}
	return "ДА";
}

int* create_empty_array(int size)
{
	return (int*)malloc(size * sizeof(int));
}

void print_array(int arr[], int size)
{
	printf("[");
	if (size <= 50)
	{
		for (int i = 0; i < size - 1; i++)
			printf("%i, ", arr[i]);
	}
	else
	{
		for (int i = 0; i < 10; i++)
			printf("%i, ", arr[i]);
		printf("... , ");
		for (int i = size - 10; i < size - 1; i++)
			printf("%i, ", arr[i]);
	}
	printf("%i]\n", arr[size - 1]);
}

void populate_array(int arr[], int size)
{
	if (size <= 6)
	{
		printf("Введите %i чисел\n", size);
		for (int i = 0; i < size; i++)
			scanf("%i", &arr[i]);
	}
	else
	{
		int range_min, range_max;
		srand((unsigned int)time(NULL));
		printf("Введите минимальное значение: ");
		scanf("%i", &range_min);
		printf("Введите максимальное значение: ");
		scanf("%i", &range_max);
		for (int i = 0; i < size; i++)
		{
			arr[i] = (double)rand() /
				(RAND_MAX + 1) * (range_max + 1 - range_min) +
				range_min;
		}
		printf("Успешно сгенерирован новый массив:\n");
		print_array(arr, size);
	}
}

int* get_array(int* size)
{
	printf("Введите размер нового массива: ");
	scanf("%i", size);
	int* arr = create_empty_array(*size);
	populate_array(arr, *size);
	return arr;
}

int* array_copy(int arr[], int size)
{
	int* new_arr, i;
	new_arr = create_empty_array(size);
	for (i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	return new_arr;
}

void recover_old_array(int* arr, int* tmp_arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		arr[i] = tmp_arr[i];
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

float t_diff(time_t begin, time_t end)
{
	return ((float)(end - begin) / CLOCKS_PER_SEC);
}