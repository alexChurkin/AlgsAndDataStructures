#pragma once

//Вспомогательные функции для сортировки вставками
//(2 вида поиска места вставки)
int find_insert_position_linearly(int arr[], int right, int* comp_count);
int find_insert_position_binary(int arr[], int right, int* comp_count);

//Функции для поиска минимального и максимального элементов
//(для сортировки подсчётом, чтобы затем уменьшить размер массива "подсчётов")
int get_min_index(int arr[], int size);
int get_max_index(int arr[], int size);

//Вспомогательная функция для сортировки слиянием
//(слияние 2-х отсортированных частей массива)
void merge_sorted_parts(
	int arr[], int l, int c, int r,
	int* comp_count, int* swap_count);