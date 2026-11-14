#include <iostream>
using namespace std;

class Account {
private:
    int pin = 1234;       // PRIVATE: Accessible ONLY inside Account

protected:
    double balance = 5000;// PROTECTED: Accessible inside Account and derived classes

public:
    string name = "Alice";// PUBLIC: Accessible everywhere
};

class SavingsAccount : public Account {
public:
    void testAccess() {
        cout << "Name (Public): " << name << endl;           // ALLOWED
        cout << "Balance (Protected): " << balance << endl; // ALLOWED
        // cout << Pin: " << pin << endl;                  // ERROR! Private is inaccessible
    }
};

int main() {
    SavingsAccount sa;
    sa.testAccess();
    cout << "Direct access from main - Name (Public): " << sa.name << endl; // ALLOWED
    // cout << sa.balance; // ERROR! Protected cannot be accessed directly from main
    return 0;
}