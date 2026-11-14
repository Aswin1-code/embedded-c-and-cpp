
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Account {
protected: // Accessible to derived classes
    int accountNumber;
    string accountHolderName;

public:
    // Base class constructor (Constructor Chaining)
    Account(int accNo, string name) {
        accountNumber = accNo;
        accountHolderName = name;
        cout << "[Base] Account Constructor Called\n";
    }

    void displayAccountInfo() const {
        cout << "Acc No: " << accountNumber << ", Holder: " << accountHolderName << endl;
    }
};

// Derived Class
class SavingsAccount : public Account {
private:
    double balance;
    double interestRate;

public:
    // Derived class constructor with constructor chaining (calling Base constructor)
    SavingsAccount(int accNo, string name, double bal, double rate) : Account(accNo, name) {
        balance = bal;
        interestRate = rate;
        cout << "[Derived] SavingsAccount Constructor Called\n";
    }

    // Function to compute interest
    void computeAndDisplayInterest() const {
        double interest = balance * (interestRate / 100.0);
        cout << "Balance: $" << balance << ", Interest Rate: " << interestRate << "%" << endl;
        cout << "Computed Interest: $" << interest << endl;
    }
};

int main() {
    cout << "=== Creating Savings Account Object ===" << endl;
    // Constructor chaining initializes both base and derived attributes
    SavingsAccount sa(1001, "Alice Smith", 5000.0, 4.5);

    cout << "\n=== Account Details & Interest ===" << endl;
    sa.displayAccountInfo();
    sa.computeAndDisplayInterest();

    return 0;
}