#include <iostream>
using namespace std;

class Camera {
public:
    void status() { cout << "Camera Status: Active\n"; }
};

class GPS {
public:
    void status() { cout << "GPS Status: Locked\n"; }
};

// Multiple Inheritance
class Drone : public Camera, public GPS {
public:
    // Overriding to resolve ambiguity or defining own status
    void status() {
        cout << "Drone System Operational.\n";
    }
};

int main() {
    Drone d;

    // 1. Calling overridden method in Drone
    d.status(); 

    // 2. Demonstrating Ambiguity Resolution using Scope Resolution Operator (::)
    cout << "\nResolving ambiguity explicitly:\n";
    d.Camera::status(); // Calls Camera's status
    d.GPS::status();    // Calls GPS's status

    return 0;
}