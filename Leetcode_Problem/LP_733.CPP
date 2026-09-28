class Solution {
public:
    void dfs(vector<vector<int>>& image, int currRow, int currCol,int initial_color, int newColor) {
        int m = image.size(); // row
        int n = image[0].size(); // colmns
 
        if (currRow < 0 || currRow >= m || currCol < 0 || currCol >= n) {
            return;
        }

        if (image[currRow][currCol] != initial_color) {
            return;
        }
        image[currRow][currCol] = newColor;

        dfs(image, currRow + 1, currCol, initial_color, newColor); // down
        dfs(image, currRow - 1, currCol, initial_color, newColor); // up
        dfs(image, currRow, currCol + 1, initial_color, newColor); // right
        dfs(image, currRow, currCol - 1, initial_color, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        if (initial_color == color) {
            return image;
        }
        dfs(image, sr, sc, initial_color, color);
        return image;
    }
};