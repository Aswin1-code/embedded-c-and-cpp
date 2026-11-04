#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// Shared memory accessible by both threads
int sharedData = 0;
int increments;
mutex mtx;
void accessSharedMemory(int threadID)
{
    for (int i = 0; i < increments; i++)
    {
        // Synchronize access to shared data
        lock_guard<mutex> lock(mtx);
        sharedData++;
        cout << "Thread " << threadID
             << " updated shared data to: "
             << sharedData << endl;
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
    cout << "\nCreating two threads..." << endl;
    thread t1(accessSharedMemory, 1);
    thread t2(accessSharedMemory, 2);
    t1.join();
    t2.join();
    cout << "\nBoth threads completed." << endl;
    cout << "Final shared data: "
         << sharedData << endl;
    cout << "Expected shared data: "
         << 2 * increments << endl;
    return 0;
}
