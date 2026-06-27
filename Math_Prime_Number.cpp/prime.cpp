#include <iostream>

using namespace std;

void isprime(int n) {
    if (n == 1) {
        cout << n << " is neither prime nor composite.";
        return;
    }

    bool check = false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            check = true;
            break;
        }
    }

    if (check==true)
        cout << n << " : is Composite";
    else
        cout << n << " : is Prime";
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    isprime(n);

    return 0;
}