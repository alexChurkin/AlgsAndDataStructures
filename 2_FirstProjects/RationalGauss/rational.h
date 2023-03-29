#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
using namespace std;

class Rational
{
private:
    int m;
    unsigned int n;
    void gcd_optimize();

public:
    Rational(int m = 0, unsigned int n = 1);
    Rational(Rational min, Rational max);

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

    friend ostream& operator<<(ostream& os, Rational r)
    {
        os << r.m << "/" << r.n;
        return os;
    }

    friend istream& operator>>(istream& is, Rational& r)
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

        r.m = stoi(str.substr(0, slash_pos));
        r.n = stoi(str.substr(slash_pos + 1, str.size() - 1));
        r.gcd_optimize();
        return is;
    }

    friend Rational abs(Rational r) {
        int m = r.getM();
        if (m < 0) {
            r.setM(-m);
        }
        return r;
    }
};