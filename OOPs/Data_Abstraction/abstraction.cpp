/*Abstraction means showing only the necessary
information and hiding the implementation details.

The user only knows what a function does,
not how it does it.
*/
#include <iostream>
using namespace std;

class Car {
public:
    void start() {
        ignition();
        fuelSupply();
        cout << "Car Started" << endl;
    }

private:
    void ignition() {
        cout << "Ignition ON" << endl;
    }

    void fuelSupply() {
        cout << "Fuel Supplied" << endl;
    }
};

int main() {
    Car c;

    c.start();

    return 0;
}