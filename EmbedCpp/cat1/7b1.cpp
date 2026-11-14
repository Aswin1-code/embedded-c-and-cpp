#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
    Student(string n, int m) : name(n), marks(m) {}

    // 1. Overload '==' operator using a member function
    bool operator==(const Student& s) {
        return this->marks == s.marks;
    }

    // 2. Overload '<' operator using a member function
    bool operator<(const Student& s) {
        return this->marks < s.marks;
    }

    void display() const {
        cout << name << " (Marks: " << marks << ")\n";
    }
};

int main() {
    Student s1("Alice", 85);
    Student s2("Bob", 90);
    Student s3("Charlie", 85);

    s1.display();
    s2.display();

    if (s1 == s3) {
        cout << "Alice and Charlie have equal marks.\n";
    }

    if (s1 < s2) {
        cout << "Alice scored less marks than Bob.\n";
    }

    return 0;
}