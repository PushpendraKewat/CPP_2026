// 1765. Map of Highest Peak
class Solution {
public:
    vector<vector<int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));

        queue<pair<int,int>> q;

        // water = 1 is source
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(isWater[i][j] == 1) {
                    q.push({i,j});
                    height[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {

            auto cell = q.front();
            q.pop();

            int row = cell.first;
            int col = cell.second;

            for(int d = 0; d < 4; d++) {

                int newRow = row + dir[d][0];
                int newCol = col + dir[d][1];

                if(newRow < 0 || newRow >= m ||
                   newCol < 0 || newCol >= n ||
                   height[newRow][newCol] != -1) {
                    continue;
                }

                height[newRow][newCol] = height[row][col] + 1;
                q.push({newRow,newCol});
            }
        }

        return height;
    }
};