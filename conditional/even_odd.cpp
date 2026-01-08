#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int a;
  cout<<"Enter a number : ";
  cin>>a;
  if(a%2==0){
    cout<<a<<" is an even number"<<endl;
  }
  else{
    cout<<a<<" is an odd number"<<endl;
  }
  return 0;
}