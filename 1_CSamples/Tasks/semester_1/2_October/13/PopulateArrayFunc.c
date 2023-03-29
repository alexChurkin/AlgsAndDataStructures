#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define RANGE_MIN 1
#define RANGE_MAX 100

/*
6. Написать функцию, для заполнения массива числами
   (если размер массива больше 5, то заполнение происходит случайными числами;
   иначе - с клавиатуры)
*/
void fill_array(int arr[], int size) {
    if(size <= 5) {
        printf("Введите %i чисел\n", size);
        for(int i = 0; i < size; i++) {
            scanf("%i", &arr[i]);
        }
    } else {
        srand((unsigned int) time(NULL));
        for (int i = 0; i < size; i++) {
            arr[i] = (double)rand() / (RAND_MAX + 1) * (RANGE_MAX - RANGE_MIN) + RANGE_MIN;
        }
    }
}

void print_array(int arr[], int size) {
    printf("[");
    for(int i = 0; i < size - 1; i++) {
        printf("%i ", arr[i]);
    }
    printf("%i]\n", arr[size - 1]);
}

void main() {
    setlocale(LC_CTYPE, "rus");
    int arr[SIZE];

    fill_array(arr, SIZE);
    printf("Массив стал таким:\n");
    print_array(arr, SIZE);
}