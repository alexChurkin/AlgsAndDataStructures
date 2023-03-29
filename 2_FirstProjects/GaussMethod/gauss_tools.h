#pragma once
double** copy_matrix(double** A, int n);
double* copy_vector(double* b, int n);
void save_to_file(double** A, double* b, int n);
void load_from_file(double**& A, double*& b, int& n);

void request_system(double**& A, double*& b, int& n);
void print_system(double** A, double* b, int n);
void print_solution(double* x, int n);
void destroy_system(double**& A, double**& A1,
    double*& x, double*& b, double*& b1, int n);