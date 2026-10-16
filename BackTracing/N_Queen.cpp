#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool canPlaceQueen(int row, int col, int n, vector<string>& board) {

    // check same column
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    // check upper-left diagonal
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    // check upper-right diagonal
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void f(int row, int n, vector<string>& board,
       vector<vector<string>>& ans) {

    if(row == n) {
        // we got answer
        ans.push_back(board);
        return;
    }

    for(int col = 0; col < n; col++) {
        if(canPlaceQueen(row, col, n, board)) {
            board[row][col] = 'Q';

            f(row + 1, n, board, ans);

            board[row][col] = '.'; // backtracking
        }
    }
}

vector<vector<string>> N_queen(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    f(0, n, board, ans);

    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<string>> ans = N_queen(n);

    for(int k = 0; k < ans.size(); k++) {
        cout << "Solution " << k + 1 << ":\n";

        for(int i = 0; i < n; i++) {
            cout << ans[k][i] << endl;
        }

        cout << endl;
    }

    return 0;
}