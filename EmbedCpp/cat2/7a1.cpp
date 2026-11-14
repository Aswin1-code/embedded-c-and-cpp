#include <iostream>
using namespace std;

// Base Class
class Sensor {
public:
    virtual void readValue() {
        cout << "Reading generic sensor value...\n";
    }
    virtual ~Sensor() {}
};

// Derived Class 1
class TemperatureSensor : public Sensor {
public:
    void readValue() override {
        cout << "Reading Temperature: 25.5 °C\n";
    }
};

// Derived Class 2 (To show how inheritance avoids code duplication)
class PressureSensor : public Sensor {
public:
    void readValue() override {
        cout << "Reading Pressure: 101.3 kPa\n";
    }
};

int main() {
    // Demonstrating runtime polymorphism using base class pointers
    Sensor* s1 = new TemperatureSensor();
    Sensor* s2 = new PressureSensor();

    s1->readValue(); // Calls TemperatureSensor override
    s2->readValue(); // Calls PressureSensor override

    delete s1;
    delete s2;
    return 0;
}