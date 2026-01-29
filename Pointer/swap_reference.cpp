#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Before swapping: " << a << " " << b << endl;
    swap(a, b);   // no & needed
    cout << "After swapping: " << a << " " << b << endl;

    return 0;
}
