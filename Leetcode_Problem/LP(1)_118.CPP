#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for(int i=0;i<numRows;i++){
            vector<int> row;
            int curr = 1;
            for(int j=0;j<=i;j++){
                row.push_back(curr);
                int next = curr * (i-j)/(j+1);
                curr = next;

            }
            triangle.push_back(row);
        }
        return triangle;
    }
};
