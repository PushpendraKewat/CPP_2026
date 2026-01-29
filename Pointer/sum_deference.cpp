#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int a,b;
    cout<<"Enter two number :";
    cin>>a>>b;
    int* ptr = &a;
    int* ptr2 = &b;
    cout << "Sum = " << (*ptr + *ptr2) << endl;
    return 0;
}