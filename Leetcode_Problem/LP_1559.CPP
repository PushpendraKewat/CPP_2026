// 1559. Detect Cycles in 2D Grid
class Solution {
public:
    vector<vector<int>> dir {
        {0,1},   // right
        {1,0},   // down
        {-1,0},  // up
        {0,-1}   // left
    };

    bool dfs(vector<vector<char>>& grid,
             vector<vector<bool>>& vis,
             int row,
             int col,
             int parent_row,
             int parent_col){

        vis[row][col] = true;

        int m = grid.size();
        int n = grid[0].size();

        for(auto& d : dir){
            int nr = row + d[0];
            int nc = col + d[1];

            if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if(grid[nr][nc] != grid[row][col])
                continue;

            if(!vis[nr][nc]){
                if(dfs(grid, vis, nr, nc, row, col))
                    return true;
            }
            else if(nr != parent_row || nc != parent_col){
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]){
                    if(dfs(grid, vis, i, j, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
};