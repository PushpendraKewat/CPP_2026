#include <iostream>

using std::cout;
using std::endl;

int main() {
    int x = 10;
    int* ptr = &x;

    cout << "x = " << x << endl;          // value of x
    cout << "*ptr = " << *ptr << endl;    // value using pointer

    cout << "&x = " << &x << endl;        // address of x
    cout << "ptr = " << ptr << endl;      // address stored in ptr

    return 0;
}
