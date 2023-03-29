#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <cmath>
using namespace std;

typedef double (*pfunc)(double);

struct Task
{
    //Интервал, на котором ищем корень
    double a, b;
    //Точность эпсилон
    double eps;
    //Найденный икс
    int x;
    //Количество шагов (максимально допустимое,
    //наше получившееся)
    int kmax, k;

    //Функция, для которой мы ищем корни
    pfunc f;
};

void solve(Task &t)
{
    t.k = 0;
    double l = t.a, r = t.b;
    double mid = (l + r) / 2;
    while (r - l > t.eps && t.k < t.kmax)
    {
        if (t.f(l) * t.f(mid) > 0)
            l = mid;
        else
            r = mid;
        t.k++;
        mid = (l + r) / 2;
    }
    t.x = mid;
}

double f1(double x)
{
    return cos(x);
}

double f2(double x)
{
    return 2*exp(x + 2) + cos(x);
}

int main()
{
    setlocale(LC_ALL, "russian");
    Task t;

    t.a = 0;
    t.b = 1;
    t.eps = 1e-6;
    t.kmax = 100;
    t.f = f1;
    solve(t);
    cout << "Корень f1: " << t.x << '\n';
    t.f = f2;
    solve(t);
    cout << "Корень f2: " << t.x << '\n';
    return 0;
}