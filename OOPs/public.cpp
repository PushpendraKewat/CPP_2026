#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
};

int main() {
    Student s;

    s.rollNo = 101;      // ✅ Allowed
    cout << s.rollNo;

    return 0;
}