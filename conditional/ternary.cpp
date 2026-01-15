#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int n;
  cout<<"Enter a number :";
  cin>>n;
  (n%2==0) ? cout<<n<<" :is even"<<endl : cout<<n<<" : is odd"<<endl;
  return 0;
}