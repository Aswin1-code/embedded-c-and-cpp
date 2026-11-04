
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex mtx;

void incrementCounter() {
    for (int i = 0; i < 100000; i++) {

        lock_guard<mutex> lock(mtx);

        counter++;

    }
}

int main() {
    thread t1(incrementCounter);
    thread t2(incrementCounter);

    t1.join();
    t2.join();

    cout << "Final counter value: " << counter << "\n";

    return 0;
}


//--------------------------------------------------------------


#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void task(int id) {
    unique_lock<mutex> lock(mtx);

    cout << "Thread " << id
         << " acquired the mutex\n";

    lock.unlock();

    cout << "Thread " << id
         << " unlocked the mutex\n";

    lock.lock();

    cout << "Thread " << id
         << " locked the mutex again\n";
}

int main() {
    thread t1(task, 1);
    thread t2(task, 2);

    t1.join();
    t2.join();

    cout << "All threads completed\n";

    return 0;
}

//--------------------------------------------------------------
//6. 🏭 Program 5 — Protecting a shared resource accessed by multiple threads

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void accessResource(int id) {
    lock_guard<mutex> lock(mtx);

    cout << "Thread " << id
         << " is accessing the resource\n";

    cout << "Thread " << id
         << " is using the resource\n";

    cout << "Thread " << id
         << " completed resource access\n";
}

int main() {
    thread t1(accessResource, 1);
    thread t2(accessResource, 2);
    thread t3(accessResource, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

//--------------------------------------------------------------
//🔩 Program 6 — Protecting a shared variable using a separate function

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int value = 0;
mutex mtx;

void increment() {
    lock_guard<mutex> lock(mtx);

    value++;
}

void worker(int id) {
    for (int i = 0; i < 1000; i++) {
        increment();
    }

    cout << "Thread " << id << " completed\n";
}

int main() {
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join();

    cout << "Final value: " << value << "\n";

    return 0;
}

//--------------------------------------------------------------
// scoped_lock


#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx1;
mutex mtx2;

int data1 = 0;
int data2 = 0;

void task() {
    scoped_lock lock(mtx1, mtx2);

    data1++;
    data2++;

    cout << "Data1: " << data1 << "\n";
    cout << "Data2: " << data2 << "\n";
}

int main() {
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();

    return 0;
}
//Acquires both mutexes and automatically releases them when the object goes out of scope.

//This is particularly useful when multiple mutexes must be acquired together.

//--------------------------------------------------------------
//

//--------------------------------------------------------------