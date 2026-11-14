#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array(int s) {
        size = s;
        data = new int[size];
    }

    // Overloading subscript operator [] as a member function
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of bounds!\n";
            exit(1);
        }
        return data[index];
    }

    ~Array() { delete[] data; }
};

int main() {
    Array arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    cout << "Element at index 1: " << arr[1] << endl;
    // arr[5] = 50; // Triggers bounds checking error
    return 0;
}