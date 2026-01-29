#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int a,b;
    cout<<"Enter two number :";
    cin>>a>>b;
    cout<<"before swapping :"<<a<<" "<<b<<endl;
    // swap

    int temp = a;
    a = b;
    b = temp;

    cout<<"After swapping :"<<a<<" "<<b<<endl;
    return 0;
}