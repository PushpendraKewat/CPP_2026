// 1162. As Far from Land as Possible
class Solution {
public:
    vector<vector<int>> dir{
        {0,1},
        {1,0},
        {-1,0},
        {0,-1}
    };

    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<pair<int,int>> q;

        // push all land cells into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }

        // all water or all land
        if(q.empty() || q.size() == n * n) {
            return -1;
        }

        int distance = -1;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                auto cell = q.front();
                q.pop();

                int row = cell.first;
                int col = cell.second;

                for(int d = 0; d < 4; d++) {

                    int newRow = row + dir[d][0];
                    int newCol = col + dir[d][1];

                    if(newRow < 0 || newRow >= n ||
                       newCol < 0 || newCol >= n ||
                       grid[newRow][newCol] == 1) {
                        continue;
                    }

                    grid[newRow][newCol] = 1;
                    q.push({newRow,newCol});
                }
            }

            distance++;
        }

        return distance;
    }
};