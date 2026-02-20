#include<iostream>
#include<string>
#include<algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string str;
    cout << "Enter the string : ";
    getline(cin, str);
    std::sort(str.begin(),str.end());
    cout<<str;
    return 0;
}