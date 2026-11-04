
#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

int counter = 0;
int increments;

atomic_flag spinLock = ATOMIC_FLAG_INIT;

void incrementCounter(int id) {
    for (int i = 0; i < increments; i++) {

        while (spinLock.test_and_set(memory_order_acquire)) {
        }

        counter++;

        spinLock.clear(memory_order_release);
    }

    cout << "Thread " << id << " completed\n";
}

int main() {
    cout << "Enter increments per thread: ";
    cin >> increments;

    thread t1(incrementCounter, 1);
    thread t2(incrementCounter, 2);

    t1.join();
    t2.join();

    cout << "Final counter: " << counter << "\n";

    return 0;
}


//--------------------------------------------------------------

#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

int arr[5] = {0, 0, 0, 0, 0};

atomic_flag spinLock = ATOMIC_FLAG_INIT;

void updateArray(int id) {
    for (int i = 0; i < 5; i++) {

        while (spinLock.test_and_set(memory_order_acquire)) {
        }

        arr[i] += id;

        spinLock.clear(memory_order_release);
    }
}

int main() {
    thread t1(updateArray, 1);
    thread t2(updateArray, 2);

    t1.join();
    t2.join();

    cout << "Final array: ";

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}

//--------------------------------------------------------------
// spin lock using separate lock and unlock functions

#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

atomic_flag spinLock = ATOMIC_FLAG_INIT;
int counter = 0;

void lock() {
    while (spinLock.test_and_set(memory_order_acquire)) {
    }
}

void unlock() {
    spinLock.clear(memory_order_release);
}

void incrementCounter(int id) {
    for (int i = 0; i < 10000; i++) {
        lock();

        counter++;

        unlock();
    }

    cout << "Thread " << id << " completed\n";
}

int main() {
    thread t1(incrementCounter, 1);
    thread t2(incrementCounter, 2);

    t1.join();
    t2.join();

    cout << "Final counter: " << counter << "\n";

    return 0;
}

//--------------------------------------------------------------