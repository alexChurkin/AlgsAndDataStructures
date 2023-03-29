#pragma once
#include "rational.h"
const int N = 3;

void request_system(Rational**& A, Rational*& b, int n = N);
void print_system(Rational** A, Rational* b, int n = N);
void print_solution(Rational* x, int n = N);
void destroy_system(Rational**& A, Rational*& x, Rational*& b, int n = N);