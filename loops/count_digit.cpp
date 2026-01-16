#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
    int n, digit, count = 0;
    cout << "Enter a number: ";
    cin >> n;

    if (n == 0) {
        count = 1;
    } else {
        int temp = n; // store the original number
        while (temp != 0) {
            digit = temp % 10; // Extract the last digit
            count++;          // Increment the digit count
            temp = temp / 10;   // Remove the last digit
        }
    }

    cout << "Number of digits in " << n << " is: " << count << endl;
    return 0;
}
