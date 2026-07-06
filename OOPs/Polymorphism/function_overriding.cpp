#include<iostream>

using namespace std;

class A{
    public:
    void show(){
        cout<<"A ka show\n";
    }
};

class B : public A{
    public:
    void show(){
        cout<<"B ka show\n";
    }
};

int main(){
    A a;
    a.show();
    B b;
    b.show();
    return 0;
}