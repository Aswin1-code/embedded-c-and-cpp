#include <iostream>

using namespace std;

// 1. Abstract Base Class
class Shape {
public:
    // Pure Virtual Function
    // '= 0' makes this an abstract class and forces derived classes to implement calculateArea()
    virtual double calculateArea() = 0; 

    // Virtual Destructor (Crucial when using base class pointers to delete derived objects)
    virtual ~Shape() {
        cout << "[Base Destructor called]\n";
    }
};

// 2. Derived Class 1: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Overriding the pure virtual function
    double calculateArea() override {
        return 3.14159 * radius * radius;
    }

    ~Circle() {
        cout << "[Circle Destructor called]\n";
    }
};

// 3. Derived Class 2: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Overriding the pure virtual function
    double calculateArea() override {
        return length * width;
    }

    ~Rectangle() {
        cout << "[Rectangle Destructor called]\n";
    }
};

int main() {
    cout << "=== Polymorphism with Pure Virtual Functions ===" << endl;

    // We CANNOT do this because Shape is abstract: Shape s; (Error!)

    // Creating derived class objects
    Circle c(5.0);        // Radius = 5.0 -> Area = ~78.54
    Rectangle r(4.0, 6.0); // Length = 4, Width = 6 -> Area = 24.0

    // Creating Base Class Pointers
    Shape* ptr1 = &c;
    Shape* ptr2 = &r;

    // Demonstrating Runtime Polymorphism using Base Class Pointers
    cout << "\nCalculating area using Base Class Pointers:" << endl;
    
    cout << "Area of Circle: " << ptr1->calculateArea() << endl;
    // Calls Circle's calculateArea() dynamically at runtime

    cout << "Area of Rectangle: " << ptr2->calculateArea() << endl;
    // Calls Rectangle's calculateArea() dynamically at runtime

    return 0;
}