#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
using namespace std;

//2^31 - 1
const long long p = 2147483647;

long long powwme(long long x, long long t, long long m) {
	long long answer = 1 % m;
	while (t) {
		if (t % 2)
			answer = answer * x % m;
        t /= 2;
		x = x * x % m;
	}
	return answer;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    long long bobr = powwme(b, p - 2, p);
    cout << (a * bobr % p);
    return 0;
}