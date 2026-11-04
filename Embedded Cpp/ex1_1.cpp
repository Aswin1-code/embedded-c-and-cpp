#include <iostream>
#include<cmath>

using namespace std;

class Rational {
private:
    int num;
    int den;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void simplify() {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int common = gcd(abs(num), abs(den));
        if (common != 0) {
            num /= common;
            den /= common;
        }
    }

public:
    Rational(int n = 0, int d = 1) : num(n), den(d) {
        if (den == 0) {
            num = 0;
            den = 1;
        }
        simplify();
    }

    friend Rational operator+(const Rational& r1, const Rational& r2);
    friend Rational operator-(const Rational& r1, const Rational& r2);
    friend Rational operator*(const Rational& r1, const Rational& r2);

    void display() const {
        if (den == 1) {
            cout << num;
        } else {
            cout << num << "/" << den;
        }
    }
};

Rational operator+(const Rational& r1, const Rational& r2) {
    int n = (r1.num * r2.den) + (r2.num * r1.den);
    int d = r1.den * r2.den;
    return Rational(n, d);
}

Rational operator-(const Rational& r1, const Rational& r2) {
    int n = (r1.num * r2.den) - (r2.num * r1.den);
    int d = r1.den * r2.den;
    return Rational(n, d);
}

Rational operator*(const Rational& r1, const Rational& r2) {
    int n = r1.num * r2.num;
    int d = r1.den * r2.den;
    return Rational(n, d);
}

int main() {
    int n1, d1, n2, d2;

    cout << "Enter numerator and denominator for R1: ";
    cin >> n1 >> d1;
    cout << "Enter numerator and denominator for R2: ";
    cin >> n2 >> d2;

    Rational r1(n1, d1);
    Rational r2(n2, d2);

    Rational sum = r1 + r2;
    Rational diff = r1 - r2;
    Rational prod = r1 * r2;

    cout << "\nR1: "; r1.display();
    cout << "\nR2: "; r2.display();

    cout << "\n\nAddition (R1 + R2)       : "; sum.display();
    cout << "\nSubtraction (R1 - R2)    : "; diff.display();
    cout << "\nMultiplication (R1 * R2) : "; prod.display();
    cout << endl;

    return 0;
}