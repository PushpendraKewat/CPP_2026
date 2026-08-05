// method 3 (with deque)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;

        int n = nums.size();
        vector<int> ans;
        deque<int> dq; // stores indices

        for (int i = 0; i < n; i++) {

            // Remove smaller elements from the back
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            int j = i-k+1;
            while (!dq.empty() && dq.front() < j) {
                dq.pop_front();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

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