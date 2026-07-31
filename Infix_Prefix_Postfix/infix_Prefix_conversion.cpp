#include<iostream>
#include<stack>
#include<string>

using std::cout;
using std::endl;
using std::stack;
using std::string;

int priority(char ch){
    if(ch =='+' || ch =='-') return 1;
    else if(ch =='*' || ch =='/') return 2;
    else return 0; // '('
}

string solve(string val1, char ch, string val2){
    string s = "";
    s.push_back(ch);
    s += val1;
    s += val2;
    return s;
}

int main(){
    string s = "(2+6)*4/8-3";

    // we need two stack
    // 1 for value and
    // 1 for char/operator
    stack<string> val;
    stack<char> op;

    for(int i=0;i<s.length();i++){

        // check if s[i] is digit
        if(s[i]>=48 && s[i]<=57){
            val.push(std::to_string(s[i]-48));
        }
        else{

            // if opening bracket
            if(s[i]=='('){
                op.push(s[i]);
            }

            // if closing bracket
            else if(s[i]==')'){

                // work
                // val1 op val2
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();

                    string val2 = val.top();
                    val.pop();

                    string val1 = val.top();
                    val.pop();

                    string ans = solve(val1,ch,val2);
                    val.push(ans);
                }

                op.pop(); // remove '('
            }

            else{

                if(op.empty() || op.top()=='('){
                    op.push(s[i]);
                }
                else if(priority(s[i])>priority(op.top())){
                    op.push(s[i]);
                }
                else{ // work

                    // val1 op val2
                    while(!op.empty() && op.top()!='(' &&
                          priority(s[i])<=priority(op.top())){

                        char ch = op.top();
                        op.pop();

                        string val2 = val.top();
                        val.pop();

                        string val1 = val.top();
                        val.pop();

                        string ans = solve(val1,ch,val2);
                        val.push(ans);
                    }

                    op.push(s[i]);
                }
            }
        }
    }

    // work
    // val1 op val2
    while(!op.empty()){

        char ch = op.top();
        op.pop();

        string val2 = val.top();
        val.pop();

        string val1 = val.top();
        val.pop();

        string ans = solve(val1,ch,val2);
        val.push(ans);
    }

    cout << val.top() << endl;

    return 0;
}