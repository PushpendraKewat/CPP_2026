#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void zigzag(int n){
    if(n==0) return;
    cout<<n;
    zigzag(n-1);
    cout<<n;
    zigzag(n-1);
    cout<<n;
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    zigzag(n);
    return 0;
}