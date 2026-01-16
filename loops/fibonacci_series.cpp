#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int n;
    cout << "Enter the number : ";
    cin >> n;

    int a = 0, b = 1, sum = 0;

    cout << "Fibonacci series up to " << n << " terms is: " << endl;

    for(int i = 0; i < n; i++){
        cout << a << " ";
        sum = a + b;
        a = b;
        b = sum;
    }

    cout << endl;
    cout << "Fibonacci of " << n << " is: " << a << endl;
    return 0;
}
