#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 1. Overloading '+' operator using a friend function
    friend Complex operator+(const Complex& c1, const Complex& c2);

    // 2. Overloading '-' operator using a friend function
    friend Complex operator-(const Complex& c1, const Complex& c2);

    // Display function
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};
Complex operator+(const Complex& c1, const Complex& c2) {
        return Complex(c1.real + c2.real, c1.imag + c2.imag);
    }
Complex operator-(const Complex& c1, const Complex& c2) {
        return Complex(c1.real - c2.real, c1.imag - c2.imag);
    }

int main() {
    Complex num1(5.0, 3.0);
    Complex num2(2.0, 1.0);

    cout << "Complex Number 1: "; num1.display();
    cout << "Complex Number 2: "; num2.display();

    Complex sum = num1 + num2;
    Complex diff = num1 - num2;

    cout << "\nAfter Addition (+): "; sum.display();
    cout << "After Subtraction (-): "; diff.display();

    return 0;
}