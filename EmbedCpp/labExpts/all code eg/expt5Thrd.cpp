//1. 🧵 Creating multiple threads with different functions
#include <iostream>
#include <thread>
using namespace std;

void sensorTask() {
    cout << "Sensor task is running\n";
}

void processingTask() {
    cout << "Processing task is running\n";
}

void communicationTask() {
    cout << "Communication task is running\n";
}

int main() {
    thread t1(sensorTask);
    thread t2(processingTask);
    thread t3(communicationTask);

    t1.join();
    t2.join();
    t3.join();

    cout << "All threads completed\n";

    return 0;
}

//-----------------------------------------------------------------------
//2. 🔢 Passing different data types to threads

#include <iostream>
#include <thread>
#include <string>
using namespace std;

void integerTask(int value) {
    cout << "Integer value: " << value << "\n";
}

void floatTask(float value) {
    cout << "Float value: " << value << "\n";
}

void stringTask(string message) {
    cout << "Message: " << message << "\n";
}

int main() {
    thread t1(integerTask, 100);
    thread t2(floatTask, 25.5f);
    thread t3(stringTask, string("Embedded C++"));

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

//-----------------------------------------------------------------------
// passing array

#include <iostream>
#include <thread>
using namespace std;

void calculateArraySum(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    cout << "Array sum: " << sum << "\n";
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    thread t1(calculateArraySum, arr, size);

    t1.join();

    return 0;
}
//-===============-===============-===============-===============-===============-===============
// same code,, but sending the sum as reference from main -- see below.. 

// Notice the '&' before resultSum: it passes the variable by reference
void calculateArraySum(int arr[], int size, int &resultSum) {
    resultSum = 0; // Reset or initialize

    for (int i = 0; i < size; i++) {
        resultSum += arr[i];
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int finalSum = 0; // This variable lives in main()

    // CRITICAL: Because std::thread copies arguments by default,
    // you MUST wrap the reference variable in std::ref()!
    thread t1(calculateArraySum, arr, size, ref(finalSum));

    // Wait for thread to finish computing
    t1.join();

    // Now main() can access the updated finalSum!
    cout << "Array sum calculated by thread and stored in main: " << finalSum << "\n";

    return 0;
}
//-===============-===============-===============-===============-===============-===============

//--------------------------------------------------------------

#include <iostream>
#include <thread>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
};

void displayEmployee(Employee e) {
    cout << "Employee ID: " << e.id << "\n";
    cout << "Employee Name: " << e.name << "\n";
    cout << "Salary: " << e.salary << "\n";
}

int main() {
    Employee e1 = {101, "Aswin", 25000};

    thread t1(displayEmployee, e1);

    t1.join();

    return 0;
}

//--------------------------------------------------------------

// using lambda function as thread... .
#include <iostream>
#include <thread>
using namespace std;

int main() {
    thread t1([]() {
        cout << "Thread executing using lambda\n";
    });

    t1.join();

    return 0;
}
/* 
// to pass an arg --using lambda.. 
another eg..
thread t1([](int x) {
    cout << "Value: " << x << "\n";
}, 50);
*/
//--------------------------------------------------------------