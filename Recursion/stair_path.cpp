#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int stair(int n){
    if(n<=2) return n;
    return stair(n-1) + stair(n-2);
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    cout<<"No of step you need the top :"<<stair(n);
    return 0;
}