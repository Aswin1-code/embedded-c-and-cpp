#include <iostream>
using namespace std;

// 1. General Class Template
template <typename T>
class Storage {
public:
    void display(T val) { cout << "General Template: " << val << endl; }
};

// 2. Specialized Class Template for 'char'
template <>
class Storage<char> {
public:
    void display(char val) { cout << "Specialized Template for CHAR: " << val << endl; }
};

int main() {
    Storage<int> s1;     s1.display(100);   // Uses general template
    Storage<char> s2;    s2.display('A');   // Uses specialized template
    return 0;
}