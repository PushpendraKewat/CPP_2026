#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n, digit, product = 1;
    cout << "Enter a number: ";
    cin >> n;

    int temp = n; // store the original number
    while (temp != 0) {
        digit = temp % 10; // extract last digit
        product *= digit;      // multiply digit to product
        temp /= 10;        // remove last digit
    }

    cout << "Product of digits in " << n << " is: " << product << endl;
    return 0;
}
