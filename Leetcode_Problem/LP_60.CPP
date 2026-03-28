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
    string helper(string original, int n, int k, string ans){
        // base case
        if(original.size() == 0) return ans;

        int fact = 1;
        for(int i = 2; i < n; i++){
            fact *= i;
        }

        int idx = k / fact;
        if(k % fact == 0) idx--;

        char ch = original[idx];

        string left = original.substr(0, idx);
        string right = original.substr(idx + 1);

        string newOriginal = left + right;

        // update k
        if(k % fact == 0) k = fact;
        else k = k % fact;

        return helper(newOriginal, n - 1, k, ans + ch);
    }

    string getPermutation(int n, int k) {
        string str = "";
        for(int i = 1; i <= n; i++){
            str += std::to_string(i);
        }

        return helper(str, n, k, "");
    }
};