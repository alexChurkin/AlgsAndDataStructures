#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double** init_matrix(int n)
{
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new double[n];
    return matrix;
}

double** copy_matrix(double** A, int n)
{
    double** A1 = init_matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A1[i][j] = A[i][j];
    return A1;
}

double* copy_vector(double* b, int n)
{
    double* b1 = new double[n];
    for (int i = 0; i < n; i++)
        b1[i] = b[i];
    return b1;
}

void save_to_file(double** A, double* b, int n) {
    string name;
    cout << "Укажите имя файла:\n";
    cin >> name;

    ofstream ofs;
    ofs.open(name);
    ofs << n << '\n';
    for (int i = 0; i < n; i++)
    {
        ofs << left;
        for (int j = 0; j < n; j++) {
            ofs.width(20);
            ofs << setprecision(15) << A[i][j] << ' ';
        }
        ofs << b[i] << '\n';
    }
    ofs.close();
    cout << "Система успешно сохранена в файл " << name << "\n";
}

void load_from_file(double** &A, double* &b, int &n) {
    string name;
    cout << "Укажите имя файла:\n";
    cin >> name;

    ifstream ifs;
    ifs.open(name);
    ifs >> n;
    A = init_matrix(n);
    b = new double[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ifs >> A[i][j];
        ifs >> b[i];
    }
    ifs.close();
}

//Вывод системы уравнений на экран
void print_system(double** A, double* b, int n)
{
    cout << fixed;
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < n; j++) {
            cout.width(10);
            cout << setprecision(5)
                << A[i][j] << ' ';
        }
        cout << " |";
        cout.width(10);
        cout << setprecision(5)
            << b[i] << "  |" << '\n';
    }
}

void print_solution(double* x, int n) {
    cout << "x = [ ";
    for (int i = 0; i < n - 1; i++) {
        cout << x[i] << ' ';
    }
    cout << x[n - 1] << "]\n";
}

//Заполнение системы с клавиатуры или случайно
//(в зависимости от n)
void request_system(double** &A, double* &b, int& n)
{
    cout << "Введите размер системы n: ";
    cin >> n;

    A = init_matrix(n);
    b = new double[n];

    if (n <= 4)
    {
        cout << "Введите уравнения:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> A[i][j];
            cin >> b[i];
        }
        return;
    }

    cout << "Матрица будет заполена автоматически.\n";
    srand((unsigned int)time(NULL));
    int range_min, range_max;
    cout << "Укажите диапазон значений: \n";
    cin >> range_min;
    cin >> range_max;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] =
                (double)rand() / (RAND_MAX + 1) * (range_max + 1 - range_min) +
                    range_min;
        }
        b[i] = (double)rand() / (RAND_MAX + 1) * (range_max + 1 - range_min) +
                    range_min;
    }
    if (n <= 10)
    {
        cout << "Успешно создана система:\n";
        print_system(A, b, n);
        cout << "\n\n";
    }
    else
    {
        cout << "Успешно создана система "
            << n << " x " << n << "\n";
    }
}

//Освобождение памяти от системы
void destroy_system(double** &A, double** &A1,
    double*& x, double*& b, double*& b1, int n)
{
    if (A != NULL) {
        for (int i = 0; i < n; i++)
            delete[] A[i];
        delete[] A;
        A = NULL;
    }
    if (A1 != NULL) {
        for (int i = 0; i < n; i++)
            delete[] A1[i];
        delete[] A1;
        A1 = NULL;
    }
    if (b != NULL) {
        delete[] b;
        b = NULL;
    }
    if (b1 != NULL) {
        delete[] b1;
        b1 = NULL;
    }
    if (x != NULL) {
        delete[] x;
        x = NULL;
    }
}