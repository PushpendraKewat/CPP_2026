class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> mxHeap;
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                mxHeap.push(matrix[i][j]);

                if (mxHeap.size() > k) {
                    mxHeap.pop();
                }
            }
        }

        return mxHeap.top();
    }
};