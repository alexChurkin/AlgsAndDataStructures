#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

/*
3. Универсальный main, сочетающий в себе вызовы различных "подпрограмм"
   (пример использования функций)
*/

//1
void run_calculator()
{
    float num1, num2;
    char op;
    float result;

    scanf("%f%c%f", &num1, &op, &num2);
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        printf("Некорректная операция\n");
    }
    printf("Результат: %f\n", result);
}

//2
void run_NOD()
{
    int a, b;
    int res = -1;

    scanf("%i %i", &a, &b);

    if (a > 0 && b == 0)
    {
        printf("HOD = %i\n", a);
        return;
    }
    else if (b > 0 && a == 0)
    {
        printf("HOD = %i\n", b);
        return;
    }

    while (res != 0)
    {
        res = a % b;
        a = b;
        b = res;
    }
    printf("HOD = %i\n", a);
}

//3
void run_factorial()
{
    int n;
    int fact = 1;
    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    printf("Факториал равен %i\n", fact);
}

//4
void run_fibonacci()
{
    int i, n, a0 = 1, a1 = 1, a2;
    scanf("%i", &n);
    printf("Output:\n", a2);
    printf("%i\n", a0);
    printf("%i\n", a1);
    for (i = 1; i < n; i++)
    {
        a2 = a0 + a1;
        a0 = a1;
        a1 = a2;
        printf("%i\n", a2);
    }
}

//5
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
    int m = 0;
    printf("Доступные команды:\n1. Калькулятор\n2. Поиск НОД\n3. Поиск факториала\n4. Последовательность Фибоначчи\n5. Узнать таблицу символов\n6. Выход\n");
    while (1)
    {
        scanf("%i", &m);
        switch (m)
        {
        case 1:
            printf("(1): Вы запустили калькулятор. Введите a<операция>b:\n");
            run_calculator();
            break;
        case 2:
            printf("(2): Вы запустили поиск НОД двух чисел. Введите числа a и b:\n");
            run_NOD();
            break;
        case 3:
            printf("(3): Вы запустили поиск факториала до n. Введите n:\n");
            run_factorial();
            break;
        case 4:
            printf("(4): Вы запустили вывод чисел Фибоначчи до заданного n. Введите n:\n");
            run_fibonacci();
            break;
        case 5:
            printf("(5): Вы запустили вывод таблицы символов. Результат:\n");
            print_table();
            break;
        case 6:
            printf("Программа завершена.");
            return;
        }
    }
}