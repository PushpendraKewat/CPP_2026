#include <iostream>

using std::cout;
using std::endl;

int main() {
    int a = 10;
    int b = 3;

    /*
      Modulus operator (%) returns the remainder of division.

      Important properties:
      1. If a < b   → a % b = a
      2. If a == b  → a % b = 0
      3. If b == 1  → a % b = 0
      4. a % a = 0
      5. works only with integers
    */

    int mod = a % b;

    cout << "The modulus of " << a << " and " << b 
         << " is: " << mod << endl;

    return 0;
}
