class Solution {
public:
    typedef pair<int,int> pi;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int ele : nums) {
            mp[ele]++;
        }

        priority_queue<pi, vector<pi>, greater<pi>> mnHeap;

        for(auto& p : mp) {
            mnHeap.push({p.second, p.first});

            if(mnHeap.size() > k) {
                mnHeap.pop();
            }
        }

        vector<int> ans;

        while(!mnHeap.empty()) {
            ans.push_back(mnHeap.top().second);
            mnHeap.pop();
        }

        return ans;
    }
};