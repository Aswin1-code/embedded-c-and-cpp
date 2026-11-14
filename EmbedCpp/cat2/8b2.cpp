#include <iostream>
using namespace std;

// 1. General Class Template for Matrix Addition
template <typename T>
class Matrix {
private:
    T val;
public:
    Matrix(T v) : val(v) {}
    void add(Matrix m) {
        cout << "Integer/Float Addition result: " << (val + m.val) << endl;
    }
};

// 2. Specialized Class Template for bool type (performs Logical OR instead of addition)
template <>
class Matrix<bool> {
private:
    bool val;
public:
    Matrix(bool v) : val(v) {}
    void add(Matrix m) {
        cout << "Bool Logical OR result: " << (val || m.val) << endl;
    }
};

int main() {
    Matrix<int> m1(10), m2(20);
    m1.add(m2); // Performs integer addition

    Matrix<bool> b1(true), b2(false);
    b1.add(b2); // Performs logical OR operation
    return 0;
}