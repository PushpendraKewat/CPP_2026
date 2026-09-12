class Solution {
public:
    typedef pair<int, pair<int, int>> pip;
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pip, vector<pip>, greater<pip>> minheap;
        // minheap element = {nums[row][col], {row, col}}
        int mx = INT_MIN;
        
        // Initialize the heap with the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i][0]);
            minheap.push({nums[i][0], {i, 0}});
        }
        
        int start = minheap.top().first, end = mx;
        
        while (true) {
            int mn = minheap.top().first;
            int row = minheap.top().second.first;
            int col = minheap.top().second.second;
            minheap.pop();
            
            // If we reached the end of a list, break the loop
            if (col == nums[row].size() - 1) break;
            
            // Push the next element from the current row
            minheap.push({nums[row][col + 1], {row, col + 1}});
            
            // Update the maximum value
            mx = max(mx, nums[row][col + 1]);
            
            // Update the range if we found a smaller one
            if (mx - minheap.top().first < end - start) {
                start = minheap.top().first;
                end = mx;
            }
        }
        
        return {start, end};
    }
};