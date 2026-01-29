#include<iostream>

using std::cout;
using std::endl;

void fun(int x = 4, int y=12){
    cout<<x<<" "<<y;
}

int main(){
    // int x = 4;
    // int y = 10;
    // fun(5,6);
    
    fun();
    return 0;
}
