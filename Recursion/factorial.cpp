#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int factorial(int n){
    if(n == 0 || n == 1) return 1;   // base case
    return n * factorial(n - 1);    
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans = factorial(n);
    cout << ans << endl;

    return 0;
}