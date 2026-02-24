#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main(){

    // string → int
    string str = "12345";
    int x = stoi(str);
    cout << x << endl;

    // int → string
    int a = 123;
    string s = std::to_string(a);
    cout << s << endl;

    // string → long long (stoll)
    string bigNum = "123456789123";
    long long y = stoll(bigNum);
    cout << y << endl;

    // long long → string
    long long b = 987654321012;
    string t = std::to_string(b);
    cout << t << endl;

    return 0; 
}