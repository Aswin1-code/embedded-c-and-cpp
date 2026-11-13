#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;

int sharedData = 0;   // The item produced/consumed
bool hasData = false; // Flag to check if data is ready

// Producer function: Produces an item
void producer() {
    for (int i = 1; i <= 5; i++) {
        unique_lock<mutex> lock(mtx);

        // Wait if data has not been consumed yet
        cv.wait(lock, [] { return !hasData; });    // cv.wait(lock, condition)  ,, return - false -> go to sleep ,, else, next line execute

        // Produce data
        sharedData = i;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Producer generated item: " << sharedData << endl;
        hasData = true; // Mark data as ready

        // Unlock and notify consumer
        lock.unlock();
        cv.notify_one();
    }
}

// Consumer function: Consumes the item
void consumer() {
    for (int i = 1; i <= 5; i++) {
        unique_lock<mutex> lock(mtx);

        // Wait until data is available
        cv.wait(lock, [] { return hasData; });

        // Consume data
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Consumer processed item: " << sharedData << endl;
        hasData = false; // Mark data as consumed

        // Unlock and notify producer
        lock.unlock();
        cv.notify_one();
    }
}

int main() {
    cout << "--- Starting Producer-Consumer Simulation ---" << endl;

    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    cout << "--- Simulation Completed ---" << endl;
    return 0;
}

/*
If your condition returns false (NOT satisfied):
The answer is NO, it is not safe.
👉 Action: The thread *GOES TO SLEEP* (stops running).

If your condition returns true (IS satisfied):
The answer is YES, it is safe!
👉 Action: The thread DOES NOT SLEEP. 
It stays awake and * KEEPS RUNNING * straight through to the next line of code.

*/