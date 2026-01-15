#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int n;
  cout<<"Enter a number :";
  cin>>n;
  if(n%3==0 || n%5==0){
    cout<<n<<" : is divisible by 3 or 5"<<endl;
  }
  else{
    cout<<n<<" is not divisible by 3 or 5"<<endl;
  }
  return 0;
}