#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

bool isPalindrome(string& s, int i, int j){
    // base case
    if(i >= j) return true;

    // mismatch
    if(s[i] != s[j]) return false;

    // recursive call
    return isPalindrome(s, i + 1, j - 1);
}

int main(){
    string s = "mom";

    if(isPalindrome(s, 0, s.length() - 1)){
        cout <<s<< " : is Palindrome";
    } else {
        cout <<s<< " : Not Palindrome";
    }

    return 0;
}