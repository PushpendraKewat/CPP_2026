#include <iostream>
#include <string>
using namespace std;

class Bike {
private:
    static int noofBike;
    string name;
    int tyresize;

public:
    Bike(string name, int tyresize) {
        this->name = name;
        this->tyresize = tyresize;
        noofBike += 10;
    }  

    void display() {
        cout << "Bike Name: " << name << endl;
        cout << "Tyre Size: " << tyresize << endl;
        cout << "No of Bikes: " << noofBike << endl;
    }

    ~Bike() {
        cout << "Object has been destroyed\n";
    }
};

int Bike::noofBike = 0;

int main() {
    Bike b1("TVS", 20);
    b1.display();

    Bike b2("Honda", 25);
    b2.display();

    return 0;
}