#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

/*
2. Создать функцию, печатающую таблицу символов (код, значение)
*/
void print_table()
{
    char c = 0;
    int i;
    for (i = 0; i < 256; i++)
    {
        c = i;
        printf("%i | %c\n", i, c);
    }
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    print_table();
}