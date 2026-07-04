#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // Constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }
};

int main() {
    Student s("Pushpendra", 20);

    cout << s.name << " " << s.age;
}