#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

bool judgeSquareSum(int c) {
    long long x = 0;
    long long y = std::sqrt(c);

    while (x <= y) {
        long long sum = x * x + y * y;

        if (sum == c) {
            cout << "Numbers are: " << x << " and " << y << endl;
            cout << x << "^2 + " << y << "^2 = " << c << endl;
            return true;
        }
        else if (sum < c) x++;
        else y--;
    }
    return false;
}

int main() {
    int c;
    cout << "Enter number: ";
    cin >> c;

    if (judgeSquareSum(c))
        cout << "Yes, it can be expressed as sum of two squares" << endl;
    else
        cout << "No, it cannot be expressed as sum of two squares" << endl;

    return 0;
}