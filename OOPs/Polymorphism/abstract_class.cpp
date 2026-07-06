#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void start() = 0;   // Pure virtual function
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike Started\n";
    }
};

int main() {
    Bike b;
    b.start();
}