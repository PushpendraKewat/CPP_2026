#include<iostream>
using namespace std;

int main(){
    int a, b;
    cout << "Enter base (a): ";
    cin >> a;
    cout << "Enter power (b): ";
    cin >> b;

    int result = 1;
    for(int i = 1; i <= b; i++){
        result *= a;
    }

    cout << a << " raised to the power " << b << " is: " << result << endl;
    return 0;
}
