#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int highestPowerOf2(int n) {
    int temp = n;

    while (n > 0) {
        temp = n;
        n = n & (n - 1);
    }

    return temp;
}

int largestPowerOf2LessThanN(int n) {
    int ans = highestPowerOf2(n);

    if (ans == n) {  // n is already a power of 2
        return ans >> 1;
    }

    return ans;
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Largest power of 2 less than " << n << " = "
         << largestPowerOf2LessThanN(n) << endl;

    return 0;
}