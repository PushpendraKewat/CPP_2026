#include <iostream>
using namespace std;

int nextPowerOf2(int n) {
    int ans = 1;

    while (ans <= n) {
        ans <<= 1;  // multiply by 2
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Smallest power of 2 greater than " << n
         << " = " << nextPowerOf2(n) << endl;

    return 0;
}