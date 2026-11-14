#include <iostream>
#include <string>
using namespace std;

// Base Class
class Battery {
protected:
    int capacity; // in mAh

public:
    // Parameterized Base Constructor
    Battery(int cap) : capacity(cap) {
        cout << "[Base Constructor] Battery capacity set to " << capacity << " mAh\n";
    }
};

// Derived Class
class Laptop : public Battery {
private:
    string brandName;

public:
    // Parameterized Derived Constructor with Constructor Chaining via Initializer List
    Laptop(int cap, string brand) : Battery(cap), brandName(brand) {
        cout << "[Derived Constructor] Laptop brand set to " << brandName << "\n";
    }

    void display() const {
        cout << "Laptop Brand: " << brandName << ", Battery Capacity: " << capacity << " mAh\n";
    }
};

int main() {
    cout << "=== Creating Laptop Object (Constructor Chaining) ===" << endl;
    // Base constructor runs first, then derived constructor
    Laptop myLaptop(5000, "Dell XPS");

    cout << "\n=== Details ===" << endl;
    myLaptop.display();

    return 0;
}