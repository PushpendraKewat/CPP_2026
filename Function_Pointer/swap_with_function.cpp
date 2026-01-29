#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void swap(int &a, int&b){
    // third variable
    // int temp = a;
    // a = b;
    // b = temp;

    // without third variable
    // a = a+b;
    // b = a-b;
    // a = a-b;

    // using xOR 
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

}

int main(){
    int a,b;
    cout<<"Enter two number :";
    cin>>a>>b;
    cout<<"before swapping :"<<a<<" "<<b<<endl;
    // swap
    swap(a,b);
    cout<<"After swapping :"<<a<<" "<<b<<endl;
    return 0;
}