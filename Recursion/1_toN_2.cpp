#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void print(int i,int n){
   if(i>n) return;
   cout<<i<<endl;
   print(i+1,n);
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    print(1,n);
    return 0;
}