#include <iostream>
#include <thread>
#include <atomic>
using namespace std;
int counter = 0;
int increments;
atomic_flag spinLock = ATOMIC_FLAG_INIT;

void incrementCounter(int threadID)
{
    for (int i = 0; i < increments; i++)
    {
        // Acquire the spin lock
        while (spinLock.test_and_set(memory_order_acquire))
        {
            // Busy waiting
        }   // Critical section
        counter++;
        cout << "Thread " << threadID
             << " | Increment: " << i + 1
             << " | Counter: " << counter << endl;
        
        // Release the spin lock
        spinLock.clear(memory_order_release);
    }
}

int main()
{
    cout << "Enter increments per thread: ";
    cin >> increments;
    if (increments <= 0)
    {
        cout << "Enter a positive number." << endl;
        return 0;
    }
    cout << "\nStarting two threads..." << endl;
    thread t1(incrementCounter, 1);
    thread t2(incrementCounter, 2);
    t1.join();
    t2.join();
    cout << "\nAll threads completed." << endl;
    cout << "Expected final counter: "
         << 2 * increments << endl;
    cout << "Actual final counter: "
         << counter << endl;
    return 0;
}
