#include<iostream>
#include<stack>
#include<string>

using std::cout;
using std::endl;
using std::stack;
using std::string;

string solve(string val1, char ch, string val2){
    string s = "";
    s.push_back('(');
    s += val1;
    s.push_back(ch);
    s += val2;
    s.push_back(')');
    return s;
}

int main(){
    string s = "79+4*8/3-";

    // we need one stack
    // 1 for value and
    stack<string> val;

    for(int i=0;i<s.length();i++){

        // check if s[i] is digit
        if(s[i]>=48 && s[i]<=57){
            val.push(std::to_string(s[i]-48));
        }
        else{

            // work
            // val1 op val2
            string val2 = val.top();
            val.pop();

            string val1 = val.top();
            val.pop();

            string ans = solve(val1, s[i], val2);
            val.push(ans);
        }
    }

    cout << val.top() << endl;

    return 0;
}