#include <iostream>
#include <bitset> // Used to print binary representation clearly

int main() {
    // Simulate a 32-bit GPIO Output Register initialized to 0 (All pins LOW)
    unsigned int gpioRegister = 0; 

    std::cout << "Initial Register: 0b" << std::bitset<8>(gpioRegister) << "\n\n";

    // 1. SET Pin 3 (Turn ON Pin 3)
    int pin = 3;
    gpioRegister = gpioRegister | (1 << pin);
    std::cout << "After SET Pin 3:     0b" << std::bitset<8>(gpioRegister) << "\n";

    // 2. TOGGLE Pin 3 (Should turn it OFF)
    gpioRegister = gpioRegister ^ (1 << pin);
    std::cout << "After TOGGLE Pin 3:  0b" << std::bitset<8>(gpioRegister) << "\n";

    // 3. SET Pin 1 and Pin 4 simultaneously
    gpioRegister = gpioRegister | (1 << 1) | (1 << 4);
    std::cout << "After SET Pin 1 & 4: 0b" << std::bitset<8>(gpioRegister) << "\n";

    // 4. TEST Pin 4 (Check if it is HIGH)
    if (gpioRegister & (1 << 4)) {
        std::cout << "Test Result: Pin 4 is HIGH (1)\n";
    } else {
        std::cout << "Test Result: Pin 4 is LOW (0)\n";
    }

    // 5. CLEAR Pin 4 (Turn OFF Pin 4)
    gpioRegister = gpioRegister & ~(1 << 4);
    std::cout << "After CLEAR Pin 4:   0b" << std::bitset<8>(gpioRegister) << "\n";

    return 0;
}