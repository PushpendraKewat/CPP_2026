#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    for(int i=65;i<=90;i++){
        cout<<static_cast<char>(i)<<" : "<<i<<endl;
    }
}