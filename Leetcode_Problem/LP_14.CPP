#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        // sort the string
        sort(strs.begin(),strs.end());

        string ans = "";
        string first = strs[0];
        string last = strs[strs.size()-1];
        int i = 0;
        // only compare first and last
        while(i < first.size() && i < last.size()){
            if(first[i]==last[i]){
                ans += first[i];
            }
            else break;
            i++;
        }
        return ans;
    }
};