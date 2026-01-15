#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if(n <= 1){
        cout << n << " is NOT a prime number";
        return 0;
    }

    bool isPrime = true;

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            isPrime = false;
            break;
        }
    }

    if(isPrime==true){
        cout << n << " : is a Prime number";
    }
    else{
        cout << n << " : is NOT a Prime number";
    }

    return 0;
}
