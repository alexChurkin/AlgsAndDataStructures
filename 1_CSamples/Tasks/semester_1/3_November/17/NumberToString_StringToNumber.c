#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/*
4. Функции перевода целого числа в строку (и наоборот)
*/

//Число в строку
char *number_to_string(long long number)
{
    if(number == 0) return "0";

    //Выясним знак
    int sign = (number < 0) ? -1 : 1;
    number = abs(number);

    //Создадим строку для результата
    char *newstring = malloc(sizeof(char) * 30);

    long long n = number, res;

    int i = 0;
    if (sign < 0)
    {
        newstring[i] = '-';
        i++;
    }

    res = n % 10;

    //Получим все цифры в обратном порядке
    //и запишем их в строку в виде символов
    while (n > 0)
    {
        newstring[i] = (res + '0');
        n /= 10;
        res = n % 10;
        i++;
    }
    newstring[i] = '\0';

    //Перевернём сегмент от (0 + offset) до (i + offset - 1) (включительно)
    int offset = 0;
    if(sign < 0) {
        offset = 1;
    }
    int j;
    for (j = offset; j < i - j - 1 + offset; j++)
    {
        int t = newstring[j];
        newstring[j] = newstring[i - j - 1 + offset];
        newstring[i - j - 1 + offset] = t;
    }
    return newstring;
}

//Строка в число (знак - тоже учитывается)
long long string_to_number(char *str)
{
    long long result = 0;
    int len = strlen(str);

    int i = 0;
    if (str[0] == '-')
        i++;

    for (; str[i] != '\0'; i++)
    {
        result += pow((long long)10, (long long)len - i - 1) * (str[i] - '0');
    }
    if (str[0] == '-')
        result = result * (-1);
    return result;
}

void main()
{
    setlocale(LC_CTYPE, "rus");

    printf("Число в строку:\n");
    char *newstring = number_to_string(-4506);
    printf("%s\n", newstring);

    printf("Строка в число:\n");
    char *test_str = "294280";
    long long result_1 = string_to_number(test_str);
    printf("%lld\n", result_1);

    char *test_str_2 = "-9875";
    long long result_2 = string_to_number(test_str_2);
    printf("%lld\n", result_2);
}