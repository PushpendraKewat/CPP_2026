#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
    int n, digit, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    int temp = n; // store the original number
    while (temp != 0) {
        digit = temp % 10; // extract last digit
        sum += digit;      // add digit to sum
        temp /= 10;        // remove last digit
    }

    cout << "Sum of digits in " << n << " is: " << sum << endl;
    return 0;
}
