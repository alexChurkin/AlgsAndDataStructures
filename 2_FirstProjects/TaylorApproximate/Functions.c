#define _USE_MATH_DEFINES
#define LN_2 0.6931471805599453094
#include <math.h>
typedef long long ll;

double my_exp(double x, int n)
{
	double result = 1.0, a = 1.0;

	ll i;
	for (i = 1; i <= n; i++)
	{
		a *= (x / i);
		result += a;
	}
	return result;
}

double my_sin(double x, int n)
{
	double result = 0.0, a = x;

	ll i;
	for (i = 1; i <= n; i++)
	{
		result += a;
		a *= (-1) * (x / (2 * i)) * (x / (2 * i + 1));
	}
	return result;
}

double my_cos(double x, int n)
{
	double result = 0.0, a = 1.0;

	ll i;
	for (i = 1; i <= n; i++)
	{
		result += a;
		a *= (-1) * (x / (2 * i - 1)) * (x / (2 * i));
	}
	return result;
}

double my_log(double x, int n)
{
	double result = 0.0, a = --x;

	ll i;
	for (i = 1; i <= n; i++)
	{
		result += a / i;
		a *= (-1) * x;
	}
	return result;
}

/* .......... Улучшенные версии .......... */

double my_improved_exp(double x, int n)
{
	double y = x;
	int k = 0;
	while (y > LN_2) {
		y -= LN_2; k++;
	}
	double k2 = 1;
	for (int i = 1; i <= k; i++) {
		k2 *= 2;
	}

	return k2 * exp(y);
}

double my_improved_sin(double x, int n)
{
	while (x > 2 * M_PI) x -= 2 * M_PI;
	while (x < -2 * M_PI) x += 2 * M_PI;
	return sin(x, n);
}

double my_improved_cos(double x, int n)
{
	while (x > 2 * M_PI) x -= 2 * M_PI;
	while (x < -2 * M_PI) x += 2 * M_PI;
	return cos(x, n);
}

double my_universal_log(double x, int n)
{
	if (x < 0) return NAN;
	else if (x == 0) return -INFINITY;

	x = (x - 1) / (x + 1);

	double result = 0.0, a = 2 * x;
	ll i;
	for (i = 1; i <= n; i++)
	{
		result += a / (2 * i - 1);
		a *= (x * x);
	}
	return result;
}