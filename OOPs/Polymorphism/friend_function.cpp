#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    Student() {
        marks = 95;
    }

    friend void display(Student);
};

void display(Student s) {
    cout << "Marks = " << s.marks << endl;
}

int main() {
    Student s1;
    display(s1);
}