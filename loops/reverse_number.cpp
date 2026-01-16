#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    int n, digit, reverse = 0;
    cout << "Enter a number: ";
    cin >> n;
    int temp = n; // store the original number
    while(temp!=0){
        digit = temp % 10; // extract last digit
        reverse = reverse * 10 + digit; // build the reversed number
        temp /= 10;        // remove last digit
    }
    cout << "Reverse of " << n << " is: " << reverse << endl;
    return 0;
}
