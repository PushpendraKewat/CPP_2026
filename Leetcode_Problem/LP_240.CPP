#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // columns

        // search row wise if row element > target we exculed that columns 
       int i=0;
       int j = n-1;
       while(i<=m-1 && j>=0){
        if(matrix[i][j]==target) return true;
        else if(matrix[i][j]>target){
            // go left
            j--;
        }
        else{ // matrix[i][j]< target 
            // go down 
            i++;
        }
       }
       return false; // if target is not found
    }
};