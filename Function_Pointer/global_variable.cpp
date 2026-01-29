#include<iostream>
using namespace std;

int x = 10;   // 👈 global variable

void fun(){
    x = 50;   // modifies global variable
    cout << "Inside function: " << x << endl;
}

int main(){
    cout << "Before function: " << x << endl;
    fun();
    cout << "After function: " << x << endl;
    return 0;
}
