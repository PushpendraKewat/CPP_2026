// 994. Rotting Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        int minutes = 0;

        vector<vector<int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty() && fresh > 0) {

            int size = q.size();

            for(int k = 0; k < size; k++) {

                auto curr = q.front();
                q.pop();

                int row = curr.first;
                int col = curr.second;

                for(int d = 0; d < 4; d++) {

                    int newRow = row + dir[d][0];
                    int newCol = col + dir[d][1];

                    if(newRow < 0 || newRow >= m ||
                       newCol < 0 || newCol >= n ||
                       grid[newRow][newCol] != 1) {
                        continue;
                    }

                    grid[newRow][newCol] = 2;
                    fresh--;

                    q.push({newRow,newCol});
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};