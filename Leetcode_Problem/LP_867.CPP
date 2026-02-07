#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();        // rows
        int m = matrix[0].size();     // columns

        vector<vector<int>> trans(m, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                trans[j][i] = matrix[i][j];
            }
        }

        return trans;
    }
};
