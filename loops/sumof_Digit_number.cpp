#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout<<"Enter a positive integer: ";
    cin>>n;
    int sum = 0;
    int last_digit;
    while(n != 0){
        last_digit = n % 10;
        sum += last_digit;
        n /= 10;
    }
    cout<<"sum of given digit number is: "<<sum;
    return 0;
}