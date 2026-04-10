#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    bool isPS(int n){
        int root = std::sqrt(n);
        if(root*root==n) return true;
        else return false;
    }
    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c;
        while(x<=y){
            if(isPS(x) && isPS(y)) // PS ->perfect square
            return true;
            else if(!isPS(y)){
                y = (int)std::sqrt(y)*(int)std::sqrt(y);
                x = c-y;
            }
            else{ // x is not perfect square
                x = ((int)std::sqrt(x)+1)*((int)std::sqrt(x)+1);
                y = c-x;
            }
        }
        return false;
    }
};