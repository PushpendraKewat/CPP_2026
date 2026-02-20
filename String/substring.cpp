#include<iostream>
#include<string>
#include<algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string str = "abcde";
    // substr(idx,lenth)
    cout<<str.substr(2,3);
    return 0;
}