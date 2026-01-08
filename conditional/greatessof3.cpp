#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int a;
  cout<<"Enter first number :";
  cin>>a;
  int b;
  cout<<"Enter second number : ";
  cin>>b;
  int c;
  cout<<"Enter third nuber :";
  cin>>c;
  if(a>b && a>c){
    cout<<a<<" : is the gretess"<<endl;
  }
  else if(b>a && b>c){
    cout<<b<<" : is the greatest"<<endl;
  }
  else{
    cout<<c<<" : is the greatest"<<endl;
  }
  return 0;
}