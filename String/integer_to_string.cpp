#include<iostream>
#include<string>
#include<algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    int x = 12345;
    string str;
    str = std::to_string(x); 
    cout<<str;
    return 0;
}