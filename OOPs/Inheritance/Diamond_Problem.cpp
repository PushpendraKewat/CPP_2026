#include <iostream>
using namespace std;

class A { // grandparent
public:
    int age;
};

class B : virtual public A { // father

};

class C : virtual public A { // mother

};

class D : public B, public C { // child

};

int main() {

    D obj;

    obj.age = 25;

    cout << obj.age << endl;

    return 0;
}