#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int counter = 0;
int increments;   // global variable
mutex mtx;
void incrementCounter(int threadID)
{
    for (int i = 0; i < increments; i++)
    {
       // mtx.lock();
        counter++;
        cout << "Thread " << threadID<< " | Increment: " << i + 1<< " | Counter: " << counter << endl;
       // mtx.unlock();
    }
}
int main()
{
    int n;
    cout << "Enter number of increments per thread: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Please enter a positive number." << endl;
        return 0;
    }
    increments = n;
    cout << "\nStarting two threads..." << endl;
    thread t1(incrementCounter, 1);
    thread t2(incrementCounter, 2);
    t1.join();
    t2.join();
    cout << "\nAll threads completed." << endl;
    cout << "Expected final counter: " << 2 * increments << endl;
    cout << "Actual final counter: " << counter << endl;
    return 0;
}

