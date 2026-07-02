#include<iostream>
#include<string>

using namespace std;

class Student{
public:
    int rollno;
    string name;
    int age;
};

int main(){ 
    Student s; // student is class and s is obejct of student class

    s.rollno = 1;
    s.name = "Pushpendra";
    s.age = 20;

    cout << s.rollno << endl;
    cout << s.name << endl;
    cout << s.age << endl;

    return 0;
}