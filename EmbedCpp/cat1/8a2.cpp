#include <iostream>
#include <string>
using namespace std;

class MotorConfig {
private:
    string motorName;
    int speedRPM;

public:
    MotorConfig(string name, int speed) : motorName(name), speedRPM(speed) {}

    // Copy Constructor (Copy Initialization)
    MotorConfig(const MotorConfig &other) {
        motorName = other.motorName + "_Copy";
        speedRPM = other.speedRPM;
        cout << "[Copy Constructor Called] Copied motor configuration.\n";
    }

    void display() const {
        cout << "Motor: " << motorName << ", Speed: " << speedRPM << " RPM\n";
    }
};

int main() {
    MotorConfig m1("StepperMotor", 1200);
    
    // Copy Initialization
    MotorConfig m2 = m1; 

    m1.display();
    m2.display();
    return 0;
}