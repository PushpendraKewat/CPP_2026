class Solution {
public:
    int solve(int idx, int capacity, vector<int>& val, vector<int>& wt) {
        if (idx == 0) {
            return (capacity / wt[0]) * val[0];
        }

        int leave = solve(idx - 1, capacity, val, wt);

        int take = 0;
        if (wt[idx] <= capacity) {
            take = val[idx] + solve(idx, capacity - wt[idx], val, wt);
        }

        return max(take, leave);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        return solve(n - 1, capacity, val, wt);
    }
};