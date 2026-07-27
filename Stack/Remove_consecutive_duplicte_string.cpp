#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using std::cout;
using std::endl;
using std::stack;
using std::string;

string removeConsecutiveDuplicate(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(s[i] == st.top()){
            continue;
        }
        else{ // s[i] ! st.top()
            st.push(s[i]);

        }
    }
    string str;
    while(!st.empty()){
        str.push_back(st.top());
        st.pop();
    }
    std::reverse(str.begin(),str.end());
    return str;
}

int main(){
    string s = "aaabbcddaabffg";
    cout<<removeConsecutiveDuplicate(s);
    return 0;
}