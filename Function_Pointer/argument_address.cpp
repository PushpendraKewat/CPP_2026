#include<iostream>


using std::cout;
using std::endl;

void fun(int &x, int &y){
    cout << "Inside function: ";
    x = 1;
    y = 2;
    cout << x << " " << y << endl;
}

int main(){
    int x = 10, y = 20;

    cout << "Before function: ";
    cout << x << " " << y << endl;

    fun(x, y);

    cout << "After function (values changed due to call by reference): ";
    cout << x << " " << y << endl;

    return 0;
}
