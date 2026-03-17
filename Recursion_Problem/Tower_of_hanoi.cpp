#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void hanoi(int n, char s, char h, char d){
    if(n==0) return;
    hanoi(n-1,s,d,h);
    cout<<s<<" -> "<<d<<endl;
    hanoi(n-1,h,s,d);
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    hanoi(n,'s','h','d');
    return 0;
}