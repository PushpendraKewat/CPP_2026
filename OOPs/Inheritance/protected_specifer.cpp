#include <iostream>
#include <string>
using namespace std;

class A{
    private:
    int a_ka_private;
    protected:
    int a_ka_protected;
    public:
    int a_ka_public;
};

class B : public A{
    public:
    int b_ka_public;
};

int main(){
    B b1;
    b1.b_ka_public;
    return 0;
}