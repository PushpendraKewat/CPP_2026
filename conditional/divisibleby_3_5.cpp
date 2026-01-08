#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int n;
  cout<<"Enter a number :";
  cin>>n;
  if(n%3==0 && n%5==0){
    cout<<n<<" : is divisible by both 3 and 5"<<endl;
  }else{
    cout<<n<<" is not divisible by both 3 and 5"<<endl;
  }
  return 0;
}