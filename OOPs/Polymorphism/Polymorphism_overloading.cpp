#include <iostream>
using namespace std;

// Polymorphism (function overloading)
class Sum {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    float add(float a, float b) {
        return a + b;
    }
};

int main() {
    Sum s;

    cout << s.add(2, 3) << endl;
    cout << s.add(2, 3, 4) << endl;
    cout << s.add(2.2f, 3.5f) << endl;

    return 0;
}