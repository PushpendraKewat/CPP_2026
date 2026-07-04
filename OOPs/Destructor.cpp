#include <iostream>
using namespace std;

class Bike {
public:
    Bike() {
        cout << "Bike Created\n";
    }

    ~Bike() {
        cout << "Bike Destroyed\n";
    }
};

int main() {
    Bike tvs;

    cout << "Inside main\n";

    return 0;
}