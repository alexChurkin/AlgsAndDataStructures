#include <stdio.h>

/*
1. Простейший калькулятор
*/
void main()
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
        printf("Incorrect operation");
    }
    printf("Result: %f", result);
}