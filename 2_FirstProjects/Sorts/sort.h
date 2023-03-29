#pragma once
void shaker_sort(int arr[], int size, int* comp_count, int* swap_count);
void selection_sort(int arr[], int size, int* comp_count, int* swap_count);
void insertion_sort(int arr[], int size, int* comp_count, int* swap_count, int mode);
void counting_sort(int arr[], int size);
void quick_sort(int arr[], int first, int last, int* comp_count, int* swap_count);
void merge_sort(int arr[], int l, int r, int* comp_count, int* swap_count);