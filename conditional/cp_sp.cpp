#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int cp;
  cout<<"Enter the cost price : ";
  cin>>cp;
  int sp;
  cout<<"Enter the selling price :";
  cin>>sp;
  if(sp>cp){
    cout<<"profit is : "<<sp-cp<<endl;
  }
  else if(sp<cp){
    cout<<"loss is : "<<cp-sp<<endl;
  }
  else{
    cout<<"No profit no loss"<<endl;
  }
}