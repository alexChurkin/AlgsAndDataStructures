#include <iostream>
#include <locale.h>
#include "tools.h"
#include "solver.h"
using namespace std;

Rational** A = NULL;
Rational* x = NULL;
Rational* b = NULL;

bool res;

void gaussificate()
{
	res = gauss_solve(A, x, b);
	if (res)
	{
		print_solution(x);
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	while (true)
	{
		request_system(A, b);
		gaussificate();
		destroy_system(A, x, b);
	}
}