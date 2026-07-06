#include <iostream>
using namespace std;

class Father {
public:
    void money() {
        cout << "Father's Money\n";
    }
};

class Mother {
public:
    void love() {
        cout << "Mother's Love\n";
    }
};

class Child : public Father, public Mother {
public:
    void study() {
        cout << "Child is Studying\n";
    }
};

int main() {
    Child c;

    c.money();
    c.love();
    c.study();
}