#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        cout << year << " is a Leap Year";
    } else {
        cout << year << " is NOT a Leap Year";
    }

    return 0;
}
