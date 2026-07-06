#include <iostream>
using namespace std;

class GrandFather {
public:
    void land() {
        cout << "Grandfather's Land\n";
    }
};

class Father : public GrandFather {
public:
    void house() {
        cout << "Father's House\n";
    }
};

class Son : public Father {
public:
    void bike() {
        cout << "Son's Bike\n";
    }
};

int main() {
    Son s;

    s.land();
    s.house();
    s.bike();
}