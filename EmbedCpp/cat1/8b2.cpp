#include <iostream>
using namespace std;

class GPIOPin {
private:
    int pinNumber;
    bool isHigh; // true for HIGH, false for LOW

public:
    GPIOPin(int pin = 0, bool high = false) : pinNumber(pin), isHigh(high) {}

    // Overload Extraction (>>) Operator
    friend istream& operator>>(istream& in, GPIOPin& p) {
        cout << "Enter Pin Number and State (1 for HIGH, 0 for LOW): ";
        in >> p.pinNumber >> p.isHigh;
        return in;
    }

    // Overload Insertion (<<) Operator
    friend ostream& operator<<(ostream& out, const GPIOPin& p) {
        out << "GPIO Pin " << p.pinNumber << " Status: " << (p.isHigh ? "HIGH" : "LOW");
        return out;
    }
};

int main() {
    GPIOPin pin;
    cin >> pin; // Input pin state
    cout << pin << endl; // Display pin state
    return 0;
}