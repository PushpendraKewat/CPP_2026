#include <iostream>

using std::cout;
using std::endl;

int main() {
    int x = 122;
    int* ptr = &x;
    cout<<*ptr<<endl;
    *ptr = 125;
    cout<<*ptr<<endl;
    return 0;
}