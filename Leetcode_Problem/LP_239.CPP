// method 2 (with stack)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ngi(n);
        stack<int> st;
        // Last element has no greater element on the right
        ngi[n - 1] = n;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ngi[i] = n;
            } else {
                ngi[i] = st.top();
            }

            st.push(i);
        }
        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            int j = i;
            while (ngi[j] < i + k) {
                j = ngi[j];
            }
            ans.push_back(nums[j]);
        }
        return ans;
    }
};


// method 1 (brute force)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n - k+1; i++) {
            int max = nums[i];

            for (int j = i; j < i + k; j++) {
                mx = max(mx, nums[j]);
            }

            ans.push_back(mx);
        }

        return ans;
    }
};