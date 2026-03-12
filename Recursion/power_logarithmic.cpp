#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int power(int a, int b){
    if(b == 0) return 1;

    int half = power(a, b/2);

    if(b % 2 == 0){
        return half * half;
    }
    else{
        return a * half * half;
    }
}

int main(){
    int a;
    cout<<"Enter base : ";
    cin>>a;
    int b;
    cout<<"Enter power : ";
    cin>>b;
    cout<<a<<" raised to power "<<b<<" is :"<<power(a,b);
    return 0;
}