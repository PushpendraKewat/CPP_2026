// 542. 01 Matrix
class Solution {
public:
    vector<vector<int>> dir{
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pair<int,int>> q;

        // push all 0's into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 0) {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            for(int d = 0; d < 4; d++) {

                int newRow = row + dir[d][0];
                int newCol = col + dir[d][1];

                if(newRow < 0 || newRow >= m ||
                   newCol < 0 || newCol >= n ||
                   ans[newRow][newCol] != -1) {
                    continue;
                }

                ans[newRow][newCol] = ans[row][col] + 1;
                q.push({newRow,newCol});
            }
        }

        return ans;
    }
};