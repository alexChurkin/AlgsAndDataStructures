#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

//Вспомогательные функции для операций над массивом
int* get_array(int* newsize);
int* create_empty_array(int size);
int* array_copy(int arr[], int size);
void populate_array(int arr[], int size);
void print_array(int arr[], int size);
void recover_old_array(int* arr, int* tmp_arr, int size);

//Функция, проверяющая отсортированность массива
//и возвращающая текстовую информацию об этом
char* is_sorted(int arr[], int size);

//Функция для обмена значений между двумя переменными
void swap(int* a, int* b);

//Функция для получения разницы во времени
float t_diff(time_t begin, time_t end);