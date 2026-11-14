#include <iostream>
using namespace std;

// 1. General Class Template
template <typename T>
class Calculator {
private:
    T num1, num2;
public:
    Calculator(T a, T b) : num1(a), num2(b) {}
    void calculate() {
        cout << "Addition: " << (num1 + num2) << endl;
        cout << "Subtraction: " << (num1 - num2) << endl;
    }
};

// 2. Full Template Specialization for 'char'
template <>
class Calculator<char> {
private:
    char c1, c2;
public:
    Calculator(char a, char b) : c1(a), c2(b) {}
    void calculate() {
        cout << "[Specialized Char] ASCII of '" << c1 << "': " << (int)c1 << endl;
        cout << "[Specialized Char] ASCII of '" << c2 << "': " << (int)c2 << endl;
    }
};

int main() {
    Calculator<int> calcInt(20, 10);
    calcInt.calculate();

    cout << endl;
    Calculator<char> calcChar('A', 'B');
    calcChar.calculate();
    return 0;
}