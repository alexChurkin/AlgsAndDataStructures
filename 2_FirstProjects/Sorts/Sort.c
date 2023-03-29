#include "helpers.h"
#include "sorthelper.h"

void shaker_sort(int arr[], int size, int* comp_count, int* swap_count)
{
	int l = 0, r = size - 1;
	bool sorted = false;
	(*comp_count) = 0;
	(*swap_count) = 0;

	while (!sorted)
	{
		sorted = true;
		for (int i = l; i < r; i++)
		{
			(*comp_count)++;
			if (arr[i] > arr[i + 1])
			{
				(*swap_count)++;
				swap(&arr[i], &arr[i + 1]);
				sorted = false;
			}
		}
		r--;
		for (int i = r; i > l; i--)
		{
			(*comp_count)++;
			if (arr[i - 1] > arr[i])
			{
				(*swap_count)++;
				swap(&arr[i - 1], &arr[i]);
				sorted = false;
			}
		}
		l++;
	}
}

void selection_sort(int arr[], int size, int* comp_count, int* swap_count)
{
	int i, j, pos;
	(*comp_count) = 0;
	(*swap_count) = 0;

	for (i = 0; i < size; i++)
	{
		pos = i;
		//Нахождение позиции минимального эл-та в неотсортированной части массива
		for (j = i; j < size; j++)
		{
			(*comp_count)++;
			if (arr[j] < arr[pos])
				pos = j;
		}
		//Перемещение минимального эл-та в конец отсортированной части
		(*swap_count)++;
		swap(&arr[pos], &arr[i]);
	}
}

void insertion_sort(int arr[], int size,
	int* comp_count, int* swap_count, int mode)
{
	int i, j, pos, tmp;
	(*comp_count) = 0;
	(*swap_count) = 0;

	for (i = 1; i < size; i++)
	{
		pos = (mode == 1) ? find_insert_position_linearly(arr, i, comp_count)
			: find_insert_position_binary(arr, i, comp_count);
		//Сдвигаем все элементы от i-го
		tmp = arr[i];
		for (j = i; j > pos; j--)
		{
			(*swap_count)++;
			arr[j] = arr[j - 1];
		}
		(*swap_count)++;
		arr[pos] = tmp;
	}
}

void counting_sort(int arr[], int size)
{
	int arr_min = arr[get_min_index(arr, size)];
	int arr_max = arr[get_max_index(arr, size)];
	int new_size = arr_max - arr_min + 1;
	int* count = create_empty_array(new_size);
	int i, j, cur = arr_min, i_in_arr = 0;

	//Обнуление элементов временного массива (для подсчётов)
	for (i = 0; i < new_size; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[arr[i] - arr_min]++;

	for (i = 0; i < new_size; i++)
	{
		for (j = 0; j < count[cur - arr_min]; j++)
		{
			arr[i_in_arr] = cur;
			i_in_arr++;
		}
		cur++;
	}
	//Освобождение памяти, выделенной для "подсчётов"
	free(count);
}

void quick_sort(int arr[], int first, int last,
	int* comp_count, int* swap_count)
{
	//Центральный элемент
	int el = arr[(first + last) / 2];

	int i = first, j = last;

	//Сортировка относительно элемента el справа и слева
	while (i < j)
	{
		while (arr[i] < el)
		{
			(*comp_count)++;
			i++;
		}
		//Т.к. условие либо не сработало совсем (но проверилось), либо сработало
		//Некое число раз и не сработало в последний раз (но тоже проверилось)
		(*comp_count)++;

		while (arr[j] > el)
		{
			(*comp_count)++;
			j--;
		}
		(*comp_count)++;

		if (i <= j)
		{
			(*swap_count)++;
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}

	//Проверка на необходимость дальнейшей сортировки
	if (first < j)
		quick_sort(arr, first, j, comp_count, swap_count);
	if (i < last)
		quick_sort(arr, i, last, comp_count, swap_count);
}

void merge_sort(
	int arr[], int l, int r,
	int* comp_count, int* swap_count)
{
	if (l == r) return;

	int c = (l + r) / 2;
	merge_sort(arr, l, c, comp_count, swap_count);
	merge_sort(arr, c + 1, r, comp_count, swap_count);
	merge_sorted_parts(arr, l, c, r, comp_count, swap_count);
}