#include <iostream>
#include <string>
using namespace std;

// Base Class
class Base {
protected:
    int baseID;

public:
    // Parameterized Constructor for Base
    Base(int id) : baseID(id) {
        cout << "[Base Constructor] Initialized baseID = " << baseID << endl;
    }
};

// Derived Class
class Derived : public Base {
private:
    int derivedID;

public:
    // Parameterized Constructor for Derived
    // Uses constructor initializer list to pass parameters up to the Base constructor
    Derived(int bID, int dID) : Base(bID), derivedID(dID) {
        cout << "[Derived Constructor] Initialized derivedID = " << derivedID << endl;
    }

    void display() const {
        cout << "Base ID: " << baseID << ", Derived ID: " << derivedID << endl;
    }
};

int main() {
    cout << "=== Creating Derived Object ===" << endl;
    // Base constructor executes first, followed by the Derived constructor
    Derived obj(100, 200);

    cout << "\n=== Displaying Object Data ===" << endl;
    obj.display();

    return 0;
}