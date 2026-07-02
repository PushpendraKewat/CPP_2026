#include <iostream>
using namespace std;

class Parent {
protected:
    int age = 50;
};

class Child : public Parent {
public:
    void display() {
        cout << age;   // ✅ Allowed
    }
};

int main() {
    Child c;
    c.display();

    // c.age;   ❌ Not allowed

    return 0;
}