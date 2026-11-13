#include <iostream>
#include <thread>
#include <mutex>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;

int increments;
mutex mtx;

void accessSharedMemory(int threadID, int *sharedData)
{
    for (int i = 0; i < increments; i++)
    {
        lock_guard<mutex> lock(mtx);

        (*sharedData)++;

        cout << "Thread " << threadID
             << " updated shared data to: "
             << *sharedData << endl;
    }
}

int main()
{
    int shmid;
    int *sharedData;

    cout << "Enter increments per thread: ";
    cin >> increments;

    // 1. Create shared memory
    shmid = shmget(IPC_PRIVATE, sizeof(int),IPC_CREAT | 0666);

    // 2. Attach shared memory
    sharedData = (int *)shmat(shmid, NULL, 0);

    // Initialize shared memory
    *sharedData = 0;

    // 3. Create threads
    thread t1(accessSharedMemory, 1, sharedData);
    thread t2(accessSharedMemory, 2, sharedData);

    // 4. Wait for threads
    t1.join();
    t2.join();

    cout << "\nFinal shared data: " << *sharedData << endl;
    cout << "Expected value: " << 2 * increments << endl;

    // 5. Detach shared memory
    shmdt(sharedData);

    // 6. Remove shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

//-----------------------------------------------------------

//-----------------------------------------------------------
// Using semaphores for synchronization
//-----------------------------------------------------------
#include <iostream>
#include <thread>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;

int increments;
sem_t sem;

void accessSharedMemory(int threadID, int *sharedData)
{
    for (int i = 0; i < increments; i++)
    {
        sem_wait(&sem);

        (*sharedData)++;

        cout << "Thread " << threadID
             << " updated shared data to: "
             << *sharedData << endl;

        sem_post(&sem);
    }
}

int main()
{
    int shmid;
    int *sharedData;

    cout << "Enter increments per thread: ";
    cin >> increments;

    // 1. Create shared memory
    shmid = shmget(IPC_PRIVATE, sizeof(int),
                   IPC_CREAT | 0666);

    if (shmid == -1)
    {
        cout << "Shared memory creation failed";
        return 1;
    }

    // 2. Attach shared memory
    sharedData = (int *)shmat(shmid, NULL, 0);

    if (sharedData == (int *)-1)
    {
        cout << "Shared memory attachment failed";
        shmctl(shmid, IPC_RMID, NULL);
        return 1;
    }

    // Initialize shared memory
    *sharedData = 0;

    // 3. Initialize semaphore
    sem_init(&sem, 0, 1);

    // 4. Create threads
    thread t1(accessSharedMemory, 1, sharedData);
    thread t2(accessSharedMemory, 2, sharedData);

    // 5. Wait for threads
    t1.join();
    t2.join();

    cout << "\nFinal shared data: " << *sharedData << endl;
    cout << "Expected value: " << 2 * increments << endl;

    // 6. Destroy semaphore
    sem_destroy(&sem);

    // 7. Detach shared memory
    shmdt(sharedData);

    // 8. Remove shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}