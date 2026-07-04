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


int main(){
    A a;
    a.a_ka_public;
    return 0;
}