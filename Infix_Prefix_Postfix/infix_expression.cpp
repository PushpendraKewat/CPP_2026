#include<iostream>
#include<stack>
#include<string>

using std::cout;
using std::endl;
using std::stack;
using std::string;

int priority(char ch){
    if(ch =='+' || ch =='-') return 1;
    else return 2;
}

int solve(int val1, char ch, int val2){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}

int main(){
    string s = "2+6*4/8-3";
    // we need two stack
    // 1 for value and
    // 1 for char/operator
    stack<int> val;
    stack<char> op;

    for(int i=0;i<s.length();i++){
        // check if s[i] is digit
        if(s[i]>=48 && s[i]<=57){
            val.push(s[i]-48);
        }
        else{
            if(op.empty()){
                op.push(s[i]);
            }
            else if(priority(s[i]) > priority(op.top())){
                op.push(s[i]);
            }
            else{ // work
                // val1 op val2
                while(!op.empty() && priority(s[i]) <= priority(op.top())){
                    char ch = op.top();
                    op.pop();

                    int val2 = val.top();
                    val.pop();

                    int val1 = val.top();
                    val.pop();

                    int ans = solve(val1, ch, val2);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }

    // work
    // val1 op val2
    while(!op.empty()){
        char ch = op.top();
        op.pop();

        int val2 = val.top();
        val.pop();

        int val1 = val.top();
        val.pop();

        int ans = solve(val1, ch, val2);
        val.push(ans);
    }

    cout << val.top() << endl;

    return 0;
}