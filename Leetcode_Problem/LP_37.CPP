// 37. Sudoku Solver
class Solution {
public:
    bool issafe(vector<vector<char>>& grid, int r, int c, char num) {
        for(int i = 0; i < 9; i++) {
            if(grid[r][i] == num) return false;
            if(grid[i][c] == num) return false;
        }

        int sr = (r / 3) * 3;
        int sc = (c / 3) * 3;

        for(int i = sr; i < sr + 3; i++) {
            for(int j = sc; j < sc + 3; j++) {
                if(grid[i][j] == num) return false;
            }
        }

        return true;
    }

    bool f(vector<vector<char>>& grid, int r, int c) {
        if(r == 9) return true;

        if(c == 9) return f(grid, r + 1, 0);

        if(grid[r][c] != '.') return f(grid, r, c + 1);

        for(char j = '1'; j <= '9'; j++) {
            if(issafe(grid, r, c, j)) {
                grid[r][c] = j;

                bool res = f(grid, r, c + 1);

                if(res) return true;

                grid[r][c] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        f(board, 0, 0);
    }
};