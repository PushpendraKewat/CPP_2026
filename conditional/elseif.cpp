#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  int marks;
  cout<<"Enter the marks (0 to 100) :";
  cin>>marks;
  if(marks < 0 || marks > 100){
    cout << "Invalid marks";
  }
  else if(marks >= 80){
    cout << "Excellent";
  }
  else if(marks >= 60){
    cout << "Very good";
  }
  else if(marks >= 40){
    cout << "Good";
  }
  else if(marks >= 30){
    cout << "Average";
  }
  else{
    cout << "Fail";
  }
  return 0;
}