#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  char ch;
  cout<<"Enter a character :";
  cin>>ch;
  // a to z => 97 to 122
  // A to Z => 65 to 90
  // 0 to 9 => 48 to 57
  int ascii = int(ch);
  // if(ascii>=65 && ascii<=90){
  //   cout<<ch<<" : Upper case is an alphabet"<<endl;
  // }
  // else if(ascii>=97 && ascii<=122){
  //   cout<<ch<<" : lower case is an alphabet"<<endl;
  // }
  // else{
  //   cout<<ch<<" : is not an alphabet"<<endl;
  // }
  // if((ascii>=65 && ascii<=90) || (ascii>=97 && ascii<=122)){
  //   cout<<ch<<" : is an alphabet"<<endl;
  // }
  if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
    cout << ch << " : is an alphabet" << endl;
  }
  else{
    cout<<ch<<" : is not an alphabet"<<endl;
  }
  return 0;
}