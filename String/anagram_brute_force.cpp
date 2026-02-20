#include<iostream>
using namespace std;

bool isAnagram(string s, string t){
    if(s.length() != t.length()) return false;

    for(int i=0;i<s.length();i++){
        bool found = false;
        for(int j=0;j<t.length();j++){
            if(s[i]==t[j]){
                found = true;
                t[j] = '#'; // marks is it being used
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

int main(){
    string s = "aab";
    string t = "aba";

    if(isAnagram(s,t))
        cout << "Anagram";
    else
        cout << "Not anagram";
}