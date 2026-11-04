#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

bool buttonPressed() {
    char input;
    cout << "\nPress 'b' + Enter to toggle the next LED (or any other key to exit): ";
    cin >> input;
    return (input == 'b' || input == 'B');    // returns true or false.. 
}
void ledOn(int led) {
    cout << "--> LED " << led << " is ON" << endl;
}
void ledOff(int led) {
    cout << "--> LED " << led << " is OFF" << endl;
}

int main() {
    int leds[] = {0, 1, 2};
    int count = 0;

    cout << "Simulated LED Button program started." << endl;

    while (true) {
        if (buttonPressed()) {
            int ledIndex = count % 3;    // for cyclic ( 3 ) sequence : 0 1 2 0 1 2 
            ledOn(leds[ledIndex]);
            this_thread::sleep_for(chrono::milliseconds(300));
            ledOff(leds[ledIndex]);
            count++;
        } else {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
