#include <iostream>
using namespace std;

// Parent Class
class Parent {
public:
    void house() {
        cout << "Parent owns a house." << endl;
    }

    void car() {
        cout << "Parent owns a car." << endl;
    }
};

// Child Class
class Child : public Parent {
public:
    void bike() {
        cout << "Child owns a bike." << endl;
    }
};

int main() {
    Child c;

    // Inherited functions
    c.house();
    c.car();

    // Child's own function
    c.bike();

    return 0;
}