// method 2 bfs
class Solution {
public:
    void bfs(vector<vector<char>>& grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});

        grid[row][col] = 'v';

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            int dr[4] = {-1,1,0,0};
            int dc[4] = {0,0,-1,1};

            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr<0 || nr>=m || nc<0 || nc>=n){
                    continue;
                }

                if(grid[nr][nc]=='0' || grid[nr][nc]=='v'){
                    continue;
                }

                grid[nr][nc] = 'v';
                q.push({nr,nc});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cc = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]=='0'){
                    // it is water skip
                    continue;
                }

                if(grid[i][j]=='v'){
                    // already visisted
                    continue;
                }

                cc++;

                bfs(grid,i,j);
            }
        }

        return cc;
    }
};

// method 1 dfs
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || row >= m || col < 0 || col >= n ||
           grid[row][col] == '0' || grid[row][col] == 'v'){
            return;
        }

        grid[row][col] = 'v';

        dfs(grid,row-1,col); // left
        dfs(grid,row+1,col); // right;
        dfs(grid,row,col-1); // up;
        dfs(grid,row,col+1); // down
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cc = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]=='0'){
                    // it is water skip
                    continue;
                }

                if(grid[i][j]=='v'){
                    // already visisted
                    continue;
                }

                cc++;

                dfs(grid,i,j);
            }
        }

        return cc;
    }
};