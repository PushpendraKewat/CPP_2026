#include <iostream>
using namespace std;

int main() {
    long long a = 123456789;
    long long b = 987654321;
    long long m = 100;

    // Addition
    cout << "Addition Property\n";
    cout << "(a + b) % m = " << (a + b) % m << endl;
    cout << "((a % m) + (b % m)) % m = "
         << ((a % m) + (b % m)) % m << endl;

    cout << endl;

    // Subtraction
    cout << "Subtraction Property\n";
    cout << "(a - b) % m = " << ((a - b) % m + m) % m << endl;
    cout << "((a % m) - (b % m) + m) % m = "
         << ((a % m) - (b % m) + m) % m << endl;

    cout << endl;

    // Multiplication
    cout << "Multiplication Property\n";
    cout << "(a * b) % m = " << (a * b) % m << endl;
    cout << "((a % m) * (b % m)) % m = "
         << ((a % m) * (b % m)) % m << endl;

    return 0;
}