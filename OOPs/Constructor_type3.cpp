#include <iostream>
using namespace std;

class Student {
public:
    int* marks;

    Student(int m) { // copy constructor(shallow copy)
        marks = new int(m);
    }
};

int main() {
    Student s1(90);
    Student s2 = s1;   // Shallow copy

    cout << *s1.marks << endl;
    cout << *s2.marks << endl;
}