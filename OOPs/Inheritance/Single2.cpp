#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int tyresize;
    int enginesize;
    string name;

public:
    Vehicle() {
        cout << "Parent constructor called" << endl;
    }
};

class Car : public Vehicle {
public:
    int steeringsize;

    Car() {
        cout << "Child constructor called" << endl;
    }

    void setData() {
        tyresize = 10;
        enginesize = 15;
        name = "Honda";
        steeringsize = 5;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Tyre Size: " << tyresize << endl;
        cout << "Engine Size: " << enginesize << endl;
        cout << "Steering Size: " << steeringsize << endl;
    }
};

int main() {
    Car honda;

    honda.setData();
    honda.display();

    // honda.tyresize = 10;    ❌ Error

    return 0;
}