#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
class Vector {
public:
    double* arr;
    Vector(size_t N) {
        arr = new double[N];
        this->N = N;
        initialize();
    }
    ~Vector() {
        delete[] arr;
    }
    double operator [] (int i) {
        return arr[i];
    }
    void operator ++ () {
        for (size_t i = 0; i < N; i++)
        {
            arr[i]++;
        }
    }
    void operator ++ (int d) {
        this->operator++();
    }
    void operator -- () {
        for (size_t i = 0; i < N; i++)
        {
            arr[i]--;
        }
    }
    void operator -- (int d) {
        this->operator--();
    }
    void print() {
        for (size_t i = 0; i < N; ++i)
        {
            cout << fixed;
            cout.precision(4);
            cout << arr[i] << " ";
        }
        cout << endl;
    }
private:
    size_t N;
    void initialize() {
        for (size_t i = 0; i < N; i++)
        {
            arr[i] = i * exp(3.14 * i / 100);
        }
    }
};
class Matrix {
public:
    double** arr;
    Matrix(size_t N, size_t M) {
        this->N = N;
        this->M = M;
        arr = new double* [N];
        for (size_t i = 0; i < N; i++)
        {
            arr[i] = new double[M];
        }
    }
    ~Matrix() {
        for (size_t i = 0; i < N; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    double at(size_t i, size_t j) {
        return arr[i][j];
    }
    double setAt(size_t i, size_t j, int val) {
        arr[i][j] = val;
    }
    void operator ++ () {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                arr[N][M]++;
            }
        }
    }
    void operator ++ (int d) {
        this->operator++();
    }
    void operator -- () {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                arr[N][M]--;
            }
        }
    }
    void operator -- (int d) {
        this->operator--();
    }
    void print() {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void fillFromVector(Vector* vector) {
        int index = 0;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                arr[i][j] = (*vector)[index];
                index++;
            }
        }
        fillFirstLineItems();
    }
private:
    size_t N;
    size_t M;
    void fillFirstLineItems() {
        for (size_t i = 0; i < N; i++)
        {
            double sum = 0;
            for (size_t j = 1; j < M; j++)
            {
                sum += arr[i][j];
            }
            arr[i][0] = sum;
        }
    }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    Vector* vector = new Vector(16);
    Matrix* matrix = new Matrix(4, 4);

    vector->print();
    matrix->fillFromVector(vector);
    matrix->print();
}
