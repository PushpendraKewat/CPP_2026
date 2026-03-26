#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;

        // even → flip
        if(k % 2 == 0){
            int prevans = kthGrammar(n - 1, k / 2);
            return 1 - prevans;
        }
        // odd → same
        else{
            return kthGrammar(n - 1, k / 2 + 1);
        }
    }
};