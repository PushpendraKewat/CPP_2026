#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Animal is eating\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking\n";
    }
};

int main() {
    Dog d;
    d.eat();
    d.bark();
}