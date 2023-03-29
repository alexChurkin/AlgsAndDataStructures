#pragma once

typedef struct input {
	double a, b, step;
	int n;
	double (*func)(double);
	double (*myfunc)(double, int);
	char* f_name;
} input;