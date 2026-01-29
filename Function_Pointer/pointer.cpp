#include<iostream>

using std::cout;
using std::endl;


void fun(int *x, int *y){
    cout << "Inside function: ";
    *x = 1;   // change value at address of x
    *y = 2;   // change value at address of y
    cout << *x << " " << *y << endl;
}

int main(){
    int x = 10, y = 20;

    cout << "Before function: ";
    cout << x << " " << y << endl;

    fun(&x, &y);   // sending addresses

    cout << "After function (values changed using pointers): ";
    cout << x << " " << y << endl;

    return 0;
}
