#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void swap(int a, int b){
    // int temp = a;
    // a = b;
    // b = temp;

    a = a+b;
    b = a-b;
    a = a-b;
}

int main(){
    int a,b;
    cout<<"Enter two number :";
    cin>>a>>b;
    //  pass by value
    cout<<"Before swapping :"<<a<<" "<<b<<endl;
    swap(a,b);
    cout<<"after swapping :"<<a<<" "<<b<<endl;
    return 0;
}