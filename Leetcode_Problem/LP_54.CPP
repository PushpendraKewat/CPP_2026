#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int sr = 0, er = m - 1;
        int sc = 0, ec = n - 1;

        vector<int> ans;

        while(sr<=er && sc<=ec){
            // left to right
            for(int j=sc;j<=ec;j++){
                ans.push_back(matrix[sr][j]);
            }
            sr++;
            // top to bottom
            for(int i=sr;i<=er;i++){
                ans.push_back(matrix[i][ec]);
            }
            ec--;
            // from bottom right to left
            if(sr<=er){
                for(int j=ec;j>=sc;j--){
                    ans.push_back(matrix[er][j]);
                }
                er--;
            }
            // botoom to top
            if(sc<=ec){
                for(int i=er;i>=sr;i--){
                    ans.push_back(matrix[i][sc]);
                }
                sc++;
            }
        }

        return ans;
    }
};