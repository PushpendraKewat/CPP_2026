#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  /*
    Boolean data type represents two values: true and false.

    Important properties:
    1. true is represented by 1
    2. false is represented by 0
    3. Boolean expressions evaluate to either true or false
    4. Used in conditional statements and loops
  */

  bool is_sunny = true;
  bool is_raining = false;

  cout << "Is it sunny? " << is_sunny << endl;
  cout << "Is it raining? " << is_raining << endl;

  cout << (5 > 3) << endl;
  cout << (2 > 4) << endl;

  return 0;
}