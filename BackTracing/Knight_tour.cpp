#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

bool isSafe(int r, int c, int n, vector<vector<int>>& board){
    return r >= 0 && r < n &&
           c >= 0 && c < n &&
           board[r][c] == -1;
}

bool solve(int r, int c, int moveNo, int n,
           vector<vector<int>>& board){

    // base case
    if(moveNo == n * n){
        return true;
    }

    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for(int k = 0; k < 8; k++){

        int nr = r + dr[k];
        int nc = c + dc[k];

        if(isSafe(nr, nc, n, board)){

            // pick
            board[nr][nc] = moveNo + 1;

            if(solve(nr, nc, moveNo + 1, n, board)){
                return true;
            }

            // backtrack
            board[nr][nc] = -1;
        }
    }

    return false;
}

int main(){
    int n = 5;

    vector<vector<int>> board(n, vector<int>(n, -1));

    board[0][0] = 1;

    if(solve(0, 0, 1, n, board)){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                cout << board[r][c] << "\t";
            }
            cout << endl;
        }
    }
    else{
        cout << "No solution exists" << endl;
    }

    return 0;
}