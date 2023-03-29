#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
#include "rational.h"
using namespace std;

void Rational::gcd_optimize()
{
    if (m == 0) {
        n = 1;
        return;
    }

    int d = n;
    int c = abs(m);

    int res = -1;
    while (res != 0)
    {
        res = d % c;
        d = c;
        c = res;
    }
    m /= d;
    n /= d;
}

Rational::Rational(int m, unsigned int n)
{
    this->m = m;
    this->n = n;
    gcd_optimize();
}

Rational::Rational(Rational min, Rational max)
{
    if (min > max) swap(min, max);

    int mmin = min.m * max.n * 5;
    int mmax = max.m * min.n * 5;

    m = (double)rand() / (RAND_MAX + 1) * (mmax + 1 - mmin) + mmin;
    n = min.n * max.n * 5;
    gcd_optimize();
}

void Rational::setM(int m)
{
    this->m = m;
    gcd_optimize();
}

int Rational::getM()
{
    return m;
}

void Rational::setN(unsigned int n)
{
    this->n = n;
    gcd_optimize();
}

unsigned int Rational::getN()
{
    return n;
}

//Сложение
Rational Rational::operator+(Rational b)
{
    Rational c;
    c.m = m * b.n + n * b.m;
    c.n = n * b.n;
    c.gcd_optimize();
    return c;
}

void Rational::operator+=(Rational b)
{
    this->m = (m * b.n + n * b.m);
    n *= b.n;
    this->gcd_optimize();
}

//Вычитание
Rational Rational::operator-(Rational b)
{
    Rational c;
    c.m = m * b.n - n * b.m;
    c.n = n * b.n;
    c.gcd_optimize();
    return c;
}

void Rational::operator-=(Rational b)
{
    this->m = m * b.n - n * b.m;
    n *= b.n;
    this->gcd_optimize();
}

//Умножение
Rational Rational::operator*(Rational b)
{
    Rational c;
    c.m = m * b.m;
    c.n = n * b.n;
    c.gcd_optimize();
    return c;
}

void Rational::operator*=(Rational b)
{
    m *= b.m;
    n *= b.n;
    this->gcd_optimize();
}

//Деление
Rational Rational::operator/(Rational b)
{
    Rational c;
    bool positive = (m * b.m) >= 0;
    c.m = abs(m) * b.n;
    c.n = n * abs(b.m);

    if (!positive)
        c.m = -c.m;
    c.gcd_optimize();
    return c;
}

void Rational::operator/=(Rational b)
{
    bool positive = (m * b.m) >= 0;
    m = abs(m) * b.n;
    n = n * abs(b.m);

    if (!positive)
        m = -m;
    this->gcd_optimize();
}

/* ....................... Сравнение ....................... */
bool Rational::operator==(Rational b)
{
    return b.m == m && b.n == n;
}

bool Rational::operator!=(Rational b)
{
    return !((*this) == b);
}

bool Rational::operator>(Rational b)
{
    return m * b.n > n * b.m;
}

bool Rational::operator>=(Rational b)
{
    return m * b.n >= n * b.m;
}

bool Rational::operator<(Rational b)
{
    return m * b.n < n* b.m;
}

bool Rational::operator<=(Rational b)
{
    return m * b.n <= n * b.m;
}