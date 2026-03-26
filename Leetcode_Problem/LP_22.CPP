#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    void helper(string s, int open, int close, int n, vector<string>& ans){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            helper(s + '(', open + 1, close, n, ans);
        }

        // add ')'
        if(close < open){
            helper(s + ')', open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("",0,0,n,ans);
        return ans;
    }
};