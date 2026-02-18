#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();     // rows
        int n = grid[0].size();  // columns

        // Step 1: flip rows where first element is 0
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }

        // Step 2: flip columns where no0 > no1
        for(int j = 0; j < n; j++){
            int no0 = 0, no1 = 0;

            for(int i = 0; i < m; i++){
                if(grid[i][j] == 0) no0++;
                else no1++;
            }

            if(no0 > no1){   // flip entire column
                for(int i = 0; i < m; i++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Step 3: calculate score
        int sum = 0;
        for(int i = 0; i < m; i++){
            int x = 1;
            for(int j = n - 1; j >= 0; j--){
                sum += grid[i][j] * x;
                x *= 2;
            }
        }

        return sum;
    }
};
