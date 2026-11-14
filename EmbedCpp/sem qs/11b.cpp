#include <iostream>

using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // 1. Default Constructor
    Distance() : feet(0), inches(0) {}

    // 2. Parameterized Constructor
    Distance(int f, int inchesVal) {
        feet = f;
        inches = inchesVal;
        
        // Normalize if inches exceed 11 (e.g., 14 inches = 1 foot 2 inches)
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    // 3. Overloading Binary '+' Operator using a Member Function
    // Syntax: ReturnType operator + (const ClassName& obj)
    Distance operator+(const Distance& d2) {
        Distance temp; // Temporary object to store the result

        // Add feet and inches
        temp.feet = this->feet + d2.feet;
        temp.inches = this->inches + d2.inches;

        // Normalize inches if they exceed 12
        if (temp.inches >= 12) {
            temp.feet += temp.inches / 12;
            temp.inches = temp.inches % 12;
        }

        return temp; // Return the combined distance object
    }

    // 4. Display Function
    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    cout << "=== Binary '+' Operator Overloading Demo ===" << endl;

    // Creating two Distance objects
    Distance dist1(5, 9);  // 5 feet 9 inches
    Distance dist2(3, 8);  // 3 feet 8 inches

    cout << "Distance 1: "; dist1.display();
    cout << "Distance 2: "; dist2.display();

    // Adding two distances using the overloaded '+' operator
    // This translates behind the scenes to: dist1.operator+(dist2)
    Distance dist3 = dist1 + dist2;

    cout << "\nTotal Distance (dist1 + dist2): ";
    dist3.display();
    // Expected output: 9 feet 5 inches (5+3 = 8ft, 9+8 = 17in -> 9ft 5in)

    return 0;
}