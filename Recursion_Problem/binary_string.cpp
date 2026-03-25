#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void binary(string s, int n){
    if(s.length() == n){
        cout << s << endl;
        return;
    }

    binary(s + '0', n);

    // only add '1' if previous is not '1'
    if(s.length() == 0 || s[s.length() - 1] == '0'){
        binary(s + '1', n);
    }
}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    binary("", n);

    return 0;
}