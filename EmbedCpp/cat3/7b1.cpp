#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 1. Generic Function Template for Swapping
template <typename T>
void genericSwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
    cout << "[Generic Swap executed]\n";
}

// Specialized Function Template for float
template <>
void genericSwap<float>(float &a, float &b) {
    if (abs(a - b) > 0.01f) {
        float temp = a;
        a = b;
        b = temp;
        cout << "[Specialized Float Swap] Swapped because difference > 0.01\n";
    } else {
        cout << "[Specialized Float Swap] Not swapped (difference <= 0.01)\n";
    }
}

// 2. Specialized Class Template for string
template <typename T>
class NameHolder {
public:
    void display(T val) { cout << "Value: " << val << endl; }
};

template <>
class NameHolder<string> {
private:
    string name;
public:
    NameHolder(string n) : name(n) {}
    void displayName() { cout << "[Specialized Class] Stored Name: " << name << endl; }
};

int main() {
    float f1 = 5.5f, f2 = 5.505f;
    genericSwap(f1, f2); // Won't swap (diff <= 0.01)

    NameHolder<string> n("Alice Johnson");
    n.displayName();
    return 0;
}