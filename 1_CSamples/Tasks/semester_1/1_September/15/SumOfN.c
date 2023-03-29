#include <stdio.h>
#include <math.h>

/* 3. Сумма n чисел, введённых с клавиатуры
  (n также вводится с клавиатуры) */
void main()
{
  int n, sum = 0, k, i;
  scanf("%i", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%i", &k);
    sum += k;
  }
  printf("Result: %i", sum);
}