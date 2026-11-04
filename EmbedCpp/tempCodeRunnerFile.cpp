#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
mutex mtx;
condition_variable cv;
int turn = 1;
void executeThread(int threadID)
{
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [threadID]()
    {
        return turn == threadID;
    });
    cout << "Thread " << threadID
         << " is executing." << endl;
    turn++;

    lock.unlock();
    cv.notify_all();
}
int main()
{
    cout << "Starting thread execution..." << endl;
    thread t1(executeThread, 1);
    thread t2(executeThread, 2);
    thread t3(executeThread, 3);
    t1.join();
    t2.join();
    t3.join();
    cout << "All threads completed in order."
         << endl;
    return 0;
}
