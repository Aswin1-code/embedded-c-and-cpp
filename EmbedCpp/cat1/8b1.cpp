#include <iostream>
using namespace std;

class Timer {
private:
    int seconds;

public:
    Timer(int s = 0) : seconds(s) {}

    // 1. Prefix ++ (++t)
    Timer& operator++() {
        ++seconds;
        return *this;
    }

    // 2. Postfix ++ (t++) - note the dummy 'int' parameter
    Timer operator++(int) {
        Timer temp = *this; // Save current state
        seconds++;
        return temp;        // Return old state
    }

    void display() const { cout << "Seconds: " << seconds << endl; }
};

int main() {
    Timer t(10);
    cout << "Initial: "; t.display();

    ++t; // Prefix
    cout << "After Prefix (++t): "; t.display();

    t++; // Postfix
    cout << "After Postfix (t++): "; t.display();
    return 0;
}