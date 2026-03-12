#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibo(n-1) + fibo(n-2);
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    cout<<fibo(n);
    return 0;
}