#include <iostream>
#include <string>

using namespace std;

// 1. First Base Class: Person
class Person {
protected:
    string name;
    int age;

public:
    void setPersonDetails(string n, int a) {
        name = n;
        age = a;
    }

    void displayPersonDetails() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// 2. Second Base Class: Department
class Department {
protected:
    string deptName;
    int deptID;

public:
    void setDeptDetails(string dName, int dID) {
        deptName = dName;
        deptID = dID;
    }

    void displayDeptDetails() const {
        cout << "Department: " << deptName << " (ID: " << deptID << ")" << endl;
    }
};

// 3. Derived Class: Employee inheriting from BOTH Person and Department
// Syntax: class Derived : accessSpecifier Base1, accessSpecifier Base2
class Employee : public Person, public Department {
private:
    int empID;
    double salary;

public:
    void setEmployeeDetails(string n, int a, string dName, int dID, int eID, double sal) {
        // Calling base class functions directly
        setPersonDetails(n, a);
        setDeptDetails(dName, dID);
        
        empID = eID;
        salary = sal;
    }

    void displayEmployeeProfile() const {
        cout << "=== Employee Profile ===" << endl;
        cout << "Employee ID: " << empID << endl;
        // Accessing inherited functions from both base classes
        displayPersonDetails();
        displayDeptDetails();
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    cout << "=== Multiple Inheritance Demo ===" << endl;

    // Create an object of the derived class Employee
    Employee emp;

    // Setting details combining Person, Department, and Employee data
    emp.setEmployeeDetails("Alice Johnson", 28, "Embedded Systems", 402, 1001, 75000.0);

    // Displaying the complete profile
    cout << endl;
    emp.displayEmployeeProfile();

    return 0;
}