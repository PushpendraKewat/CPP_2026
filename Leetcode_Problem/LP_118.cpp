// Run Time Error

#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for(int i = 0; i < numRows; i++){
            vector<int> row;
            long long val = 1;   // First element is always 1

            for(int j = 0; j <= i; j++){
                row.push_back(val);
                val = val * (i - j) / (j + 1); 
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};

