// 130 surronded regoin 
class Solution {
public:
    vector<vector<int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    void dfs(vector<vector<char>>& board, int row, int col) {

        int m = board.size();
        int n = board[0].size();

        if(row < 0 || row >= m ||
           col < 0 || col >= n ||
           board[row][col] != 'O') {
            return;
        }

        board[row][col] = '#';

        for(int d = 0; d < 4; d++) {
            int newRow = row + dir[d][0];
            int newCol = col + dir[d][1];

            dfs(board, newRow, newCol);
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // first row
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                dfs(board, 0, j);
            }
        }

        // last row
        for(int j = 0; j < n; j++) {
            if(board[m - 1][j] == 'O') {
                dfs(board, m - 1, j);
            }
        }

        // first column
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0);
            }
        }

        // last column
        for(int i = 0; i < m; i++) {
            if(board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};