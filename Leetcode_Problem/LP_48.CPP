#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // step 1 transpose the matrix
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                std::swap(matrix[i][j],matrix[j][i]);
            }
        }
        // step 2 now reverse the matrix with or without built in reverse
        // for(int i=0;i<n;i++){
        //     reverse(matrix[i].begin(),matrix[i].end());
        // }

        // without build in reverse
        for(int i=0;i<n;i++){
            int left = 0, right = n-1;
            while(left<right){
                std::swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};