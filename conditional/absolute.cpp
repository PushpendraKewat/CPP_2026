#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int n;
  cout<<"Enter a number : ";
  cin>>n;
  if(n>=0){
    cout<<"The absolute value of "<<n<<" is "<<n<<endl;
  }
  else{
    cout<<"The absolute value of "<<n<<" is "<<-n<<endl;
  }
  return 0;
}