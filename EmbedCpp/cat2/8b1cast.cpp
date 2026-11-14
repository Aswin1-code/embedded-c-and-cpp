#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { cout << "Animal sound\n"; }
    virtual ~Animal() {} // Good practice when deleting base pointers
};

class Dog : public Animal {
public:
    void sound() override { cout << "Dog barks\n"; }
    void barkInfo() { cout << "Dog-only function\n"; }
};

int main() {
    // 1. Upcasting (Derived pointer stored in Base pointer)
    Animal* a = new Dog();

    // 2. Dynamic Casting (Safely converting Base pointer back to Derived)
    if (Dog* d = dynamic_cast<Dog*>(a)) {
        d->sound();
        d->barkInfo();
    }

    // 3. Object Slicing (Derived object copied by value into Base object)
    Dog d1;
    Animal a1 = d1; 
    a1.sound(); // Outputs "Animal sound" because Dog part was sliced off

    delete a;
    return 0;
}
