// 417. Pacific Atlantic Water Flow
class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int m; // rows
    int n; // columns

    vector<vector<bool>> bfs(queue<pair<int,int>>& q, vector<vector<int>>& heights) {

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(!q.empty()) {

            auto cell = q.front();
            q.pop();

            int i = cell.first;
            int j = cell.second;

            if(visited[i][j]) continue;

            visited[i][j] = true;

            for(int d = 0; d < 4; d++) {

                int newRow = i + dir[d][0];
                int newCol = j + dir[d][1];

                if(newRow < 0 || newRow >= m ||
                   newCol < 0 || newCol >= n) {
                    continue;
                }

                if(visited[newRow][newCol]) continue;

                // reverse BFS:
                // move from ocean towards higher/equal cells
                if(heights[newRow][newCol] >= heights[i][j]) {
                    q.push({newRow, newCol});
                }
            }
        }

        return visited;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        queue<pair<int,int>> pacific;
        queue<pair<int,int>> atlantic;

        // left and right borders
        for(int i = 0; i < m; i++) {
            pacific.push({i, 0});
            atlantic.push({i, n - 1});
        }

        // top and bottom borders
        for(int j = 0; j < n; j++) {
            pacific.push({0, j});
            atlantic.push({m - 1, j});
        }

        vector<vector<bool>> pacificVisited = bfs(pacific, heights);
        vector<vector<bool>> atlanticVisited = bfs(atlantic, heights);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};