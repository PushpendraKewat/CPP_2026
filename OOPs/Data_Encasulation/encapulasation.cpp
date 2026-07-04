/*Encapsulation means wrapping data (variables)
 and functions (methods) into a single unit (class)
  and restricting direct access to the data
   using access specifiers (private, protected, public).
*/

#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;   // Hidden data

public:
    // Constructor
    BankAccount(double b) {
        balance = b;
    }

    // Setter
    void deposit(double amount) {
        balance += amount;
    }

    // Getter
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(1000);

    account.deposit(500);

    cout << "Balance: " << account.getBalance() << endl;

    // account.balance = 2000;   // ❌ Error (balance is private)

    return 0;
}