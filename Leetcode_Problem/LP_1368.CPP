// 1368. Minimum Cost to Make at Least One Valid Path in a Grid
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        vector<vector<int>> dir = {
            {0, 1},   // Right
            {0, -1},  // Left
            {1, 0},   // Down
            {-1, 0}   // Up
        };

        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();

            int x = curr.first; // x coordinate
            int y = curr.second; // y corrdinate
            int wt = grid[x][y];

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0]; // next x coordinate
                int ny = y + dir[i][1];    // next y

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int cost = (grid[x][y] == i + 1) ? 0 : 1;

                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};