#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;   // Found a divisor
    }

    return true;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " is Prime";
    else
        cout << n << " is Composite";

    return 0;
}