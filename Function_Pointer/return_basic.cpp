#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int sum(int x,int y){
    return x+y;
}

int main(){
    int a,b;
    cout<<"Enter two number :";
    cin>>a>>b;
    int result = sum(a,b);
    cout<<"Sum of a & b is :"<<result;
    return 0;
}