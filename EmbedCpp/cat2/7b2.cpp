#include <iostream>
using namespace std;

// Base Class
class Peripheral {
public:
    // Virtual Destructor (Crucial to prevent memory leaks in polymorphism)
    virtual ~Peripheral() {
        cout << "[Base Destructor Called]\n";
    }

    // Virtual Function
    virtual void connect() {
        cout << "Connecting generic peripheral...\n";
    }
};

// Derived Class 1
class Keyboard : public Peripheral {
public:
    Keyboard() { cout << "Keyboard allocated.\n"; }
    ~Keyboard() { cout << "[Keyboard Destructor Called]\n"; }
    
    void connect() override {
        cout << "Keyboard connected via USB.\n";
    }
};

// Derived Class 2
class Mouse : public Peripheral {
public:
    Mouse() { cout << "Mouse allocated.\n"; }
    ~Mouse() { cout << "[Mouse Destructor Called]\n"; }
    
    void connect() override {
        cout << "Mouse connected via Bluetooth.\n";
    }
};

int main() {
    cout << "=== Dynamic Allocation with Base Pointers ===" << endl;

    Peripheral* dev1 = new Keyboard();
    Peripheral* dev2 = new Mouse();

    cout << "\n--- Calling connect() ---" << endl;
    dev1->connect();
    dev2->connect();

    cout << "\n--- Deleting Objects (Testing Virtual Destructor) ---" << endl;
    // Because destructors are virtual, both Derived and Base destructors execute correctly
    delete dev1;
    delete dev2;

    return 0;
}