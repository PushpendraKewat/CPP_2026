#include <iostream>

using namespace std;

class Calculator {
public:
    int a;
    int b;

    void add() {
        cout << "a + b = " << a + b << endl;
    }

    void subtract() {
        cout << "a - b = " << a - b << endl;
    }

    void multiply() {
        cout << "a * b = " << a * b << endl;
    }

    void divide() {
        cout << "a / b = " << a / b << endl;
    }
};

int main() {
    Calculator c;

    c.a = 10;
    c.b = 20;

    c.add();
    c.subtract();
    c.multiply();
    c.divide();

    return 0;
}