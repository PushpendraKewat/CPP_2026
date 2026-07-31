#include<iostream>
#include<stack>
#include<string>

using std::cout;
using std::endl;
using std::stack;
using std::string;

int solve(int val1, char ch, int val2){
    if(ch == '+') return val1 + val2;
    else if(ch == '-') return val1 - val2;
    else if(ch == '*') return val1 * val2;
    else return val1 / val2;
}

int main(){
    string s = "79+4*8/3-";

    // we need one stack
    // 1 for value and
    stack<int> val;

    for(int i=0;i<s.length();i++){

        // check if s[i] is digit
        if(s[i]>=48 && s[i]<=57){
            val.push(s[i]-48);
        }
        else{

            // work
            // val1 op val2
            int val2 = val.top();
            val.pop();

            int val1 = val.top();
            val.pop();

            int ans = solve(val1, s[i], val2);
            val.push(ans);
        }
    }

    cout << val.top() << endl;

    return 0;
}