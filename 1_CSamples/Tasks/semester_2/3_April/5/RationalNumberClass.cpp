#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
using namespace std;

/*
1. Тип даннных рациональное число (m / n)
*/
class Rational
{
private:
    int m;
    unsigned int n;
    void gcd_optimize();

public:
    Rational(int m = 0, unsigned int n = 1);

    void setM(int m);
    int getM();

    void setN(unsigned int n);
    unsigned int getN();

    //Сложение
    Rational operator+(Rational b);
    void operator+=(Rational b);

    //Вычитание
    Rational operator-(Rational b);
    void operator-=(Rational b);

    //Умножение
    Rational operator*(Rational b);
    void operator*=(Rational b);

    //Деление
    Rational operator/(Rational b);
    void operator/=(Rational b);

    //Сравнение
    bool operator==(Rational b);
    bool operator!=(Rational b);

    bool operator>(Rational b);
    bool operator>=(Rational b);

    bool operator<(Rational b);
    bool operator<=(Rational b);

    friend ostream &operator<<(ostream &os, Rational r)
    {
        os << r.m << "/" << r.n;
        return os;
    }

    friend istream &operator>>(istream &is, Rational &r)
    {
        string str;
        cin >> str;

        int slash_pos = -1;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '/')
            {
                slash_pos = i;
                break;
            }
        }
        if (slash_pos == -1)
        {
            cout << "Некорректный ввод";
            return is;
        }

        r.m = stod(str.substr(0, slash_pos));
        r.n = stod(str.substr(slash_pos + 1, str.size() - 1));
        r.gcd_optimize();
        return is;
    }
};

void Rational::gcd_optimize()
{
    if (m == 0)
        return;

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
    return m * b.n < n * b.m;
}

bool Rational::operator<=(Rational b)
{
    return m * b.n <= n * b.m;
}

//MAIN
int main()
{
    setlocale(LC_ALL, "russian");
    //Благодаря значениям по умолчанию можем использовать класс вот так
    //x(2, 3), y(0, 1), z(3, 1)
    //Rational x(2, 3), y, z(3);

    Rational a, b;
    cout << "Введите 2 рациональных числа в формате a/b (с пробелом):\n";
    cin >> a >> b;

    cout << "a + b = " << a + b << '\n';
    a += b;
    cout << "a += b = " << a << '\n';
    a -= b;
    cout << "a -= b = " << a << '\n';
    cout << "a - b = " << a - b << '\n';

    cout << "a * b = " << a * b << '\n';
    a *= b;
    cout << "a *= b = " << a << '\n';
    a /= b;
    cout << "a /= b = " << a << '\n';
    cout << "a / b = " << a / b << "\n\n";

    cout << "a > b: " << (a > b) << '\n';
    cout << "a >= b: " << (a >= b) << '\n';
    cout << "a < b: " << (a < b) << '\n';
    cout << "a <= b: " << (a <= b) << '\n';
    return 0;
}