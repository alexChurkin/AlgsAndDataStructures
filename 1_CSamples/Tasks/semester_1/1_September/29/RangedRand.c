#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void run_ranged_rand_demo(int range_min, int range_max, int n)
{
   int i;
   for (i = 0; i < n; i++)
   {
      int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
      printf("  %6d\n", u);
   }
}
/* Сужение результата rand до нужного диапазона (range_min <= random number < range_max) */
void main()
{
   setlocale(LC_ALL, "");
   srand((unsigned int)time(NULL));
   run_ranged_rand_demo(1, 11, 10);
}