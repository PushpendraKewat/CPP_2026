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
    cin >> str;

    int n = str.length();

    if(n % 2 != 0){
        cout << "String length is not even";
        return 0;
    }

    cout << "Second half : " << str.substr(n/2, n/2);

    return 0;
}