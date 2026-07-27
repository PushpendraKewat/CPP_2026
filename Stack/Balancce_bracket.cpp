#include<iostream>
#include<string>
#include<stack>

using std::cout;
using std::endl;
using std::stack;
using std::string;

bool isBalance(string str){
    stack<char> st;
    // if you see opening bracket then push
    // into stack
    int i=0;
    while(i < str.size()){
        if(str[i] =='('){
            st.push(str[i]);
            i++;
        }
        else if(str[i] ==')'){
            if(st.empty()) return false;
            else{
                st.pop();
            }
            i++;
        }
    }
    if(st.empty()) return true;
    else return false;
}

int main(){
    string str = "()()()";
    cout<<isBalance(str);
    return 0;
}