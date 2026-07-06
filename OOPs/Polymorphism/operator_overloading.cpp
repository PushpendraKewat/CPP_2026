#include <iostream>
using namespace std;

class ComplexNumber {
public:
    int real;
    int imaginary;

    ComplexNumber operator+(ComplexNumber &c) {
        ComplexNumber temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }
};

int main() {
    ComplexNumber c1, c2;

    c1.real = 5;
    c1.imaginary = 10;

    c2.real = 15;
    c2.imaginary = 20;

    ComplexNumber c3 = c1 + c2;

    cout << "Real = " << c3.real << endl;
    cout << "Imaginary = " << c3.imaginary << endl;
}