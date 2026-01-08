#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  /*
    This program calculates the area of a circle given its radius.

    Formula:
    Area = π * r^2
    where π (pi) is approximately 3.14159
  */

  const float PI = 3.14159;
  float radius;

  cout << "Enter the radius of the circle: ";
  cin >> radius;

  float area = PI * radius * radius;

  cout << "The area of the circle with radius " << radius << " is " << area << endl;

  return 0;
}