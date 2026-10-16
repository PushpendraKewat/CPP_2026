#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void f(int row, int col, vector<vector<int>>& maze, int n,
       string path, vector<string>& ans,
       vector<vector<bool>>& vis) {

    if(row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    vis[row][col] = true;

    // Down
    if(row + 1 < n && maze[row + 1][col] == 1 && !vis[row + 1][col]) {
        f(row + 1, col, maze, n, path + 'D', ans, vis);
    }

    // Left
    if(col - 1 >= 0 && maze[row][col - 1] == 1 && !vis[row][col - 1]) {
        f(row, col - 1, maze, n, path + 'L', ans, vis);
    }

    // Right
    if(col + 1 < n && maze[row][col + 1] == 1 && !vis[row][col + 1]) {
        f(row, col + 1, maze, n, path + 'R', ans, vis);
    }

    // Up
    if(row - 1 >= 0 && maze[row - 1][col] == 1 && !vis[row - 1][col]) {
        f(row - 1, col, maze, n, path + 'U', ans, vis);
    }

    vis[row][col] = false; // backtracking
}

vector<string> ratInMaze(vector<vector<int>>& maze, int n) {
    vector<string> ans;

    if(n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        return ans;
    }

    vector<vector<bool>> vis(n, vector<bool>(n, false));

    f(0, 0, maze, n, "", ans, vis);

    std::sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    int n;
    cout << "Enter maze size: ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    cout << "Enter maze (0 = blocked, 1 = open):\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<string> ans = ratInMaze(maze, n);

    if(ans.empty()) {
        cout << "No path found.\n";
    } else {
        cout << "Possible paths:\n";

        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }

    return 0;
}