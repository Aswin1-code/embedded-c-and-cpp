#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

// Shared Buffer variables
int sharedData = 0;
bool hasData = false;

// Spinlock using std::atomic_flag (Modern C++ lightweight spin lock)
std::atomic_flag spinLock = ATOMIC_FLAG_INIT;

// Function to acquire the spinlock (busy-wait loop)
void lockSpin() {
    // test_and_set() returns true if it was already set, 
    // so the loop spins continuously until it successfully acquires the lock (returns false).
    while (spinLock.test_and_set(std::memory_order_acquire)) {
        // Busy waiting (spinning)
    }
}

// Function to release the spinlock
void unlockSpin() {
    spinLock.clear(std::memory_order_release);
}

// Producer Function
void producer() {
    for (int i = 1; i <= 5; ++i) {
        // Busy-wait loop until buffer is empty
        while (true) {
            lockSpin();
            if (!hasData) {
                sharedData = i; // Produce item
                hasData = true;
                cout << "[Producer] Produced: " << sharedData << endl;
                unlockSpin();
                break;
            }
            unlockSpin();
            std::this_thread::yield(); // Yield CPU while waiting
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Consumer Function
void consumer() {
    for (int i = 1; i <= 5; ++i) {
        // Busy-wait loop until buffer has data
        while (true) {
            lockSpin();
            if (hasData) {
                cout << "[Consumer] Consumed: " << sharedData << endl;
                hasData = false; // Consume item
                unlockSpin();
                break;
            }
            unlockSpin();
            std::this_thread::yield(); // Yield CPU while waiting
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    cout << "=== Producer-Consumer with Spinlock Demo ===" << endl;

    thread p(producer);
    thread c(consumer);

    p.join();
    c.join();

    cout << "Simulation completed successfully." << endl;
    return 0;
}