#include<iostream>
#include<string>
#include<algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string s = "physicswallah";
    string t = "wallahphysics";
    if(s.length() != t.length()){
        cout << "not anagram";
    }
    std::sort(s.begin(),s.end());
    std::sort(t.begin(),t.end());
    if(s==t){
        cout<<"S and T are anagram";
    }
    else{
        cout<<"not anagram";
    }
    return 0;
}