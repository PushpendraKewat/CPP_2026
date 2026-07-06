#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void show() {
        cout << "Vehicle\n";
    }
};

class Bike : public Vehicle {
public:
    void show() override {
        cout << "Bike\n";
    }
};

int main() {
    Bike b;
    Vehicle* ptr = &b;

    ptr->show();
}