#pragma once
bool gauss_solve(double** A, double*& x, double* b, int n);
double error_check(double** A, double* b, double* x, int n);