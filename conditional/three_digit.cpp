#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int n;
  cout<<"Enter a three digit number :";
  cin>>n;
  if(n>=100 && n<1000){
    cout<<n<<" : is a three digit number"<<endl;
  }
  else {
    cout<<"Please enter a valid three digit number"<<endl;
  }
  return 0;
}