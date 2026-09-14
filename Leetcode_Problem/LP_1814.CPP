// method 2 unordered map
class Solution {
public:
    int rev(int n) {
        int r = 0;
        while (n > 0) {
            r *= 10;
            r += (n % 10);
            n /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;
        long long count = 0;
        const int mod = 1e9 + 7;

        // transfor nums[i] - rev(nums[i])
        for (int i = 0; i < n; i++) {
            nums[i] -= rev(nums[i]);
        }
        // strore 
        for (int i = 0; i < n; i++) {
            if (m.find(nums[i]) != m.end()) {
                count = (count + m[nums[i]]) % mod;
            }
            m[nums[i]]++;
        }

        return count;
    }
};

// method 1 brute forece
class Solution {
public:
    int rev(int  n){
        int r = 0;
        while(n>0){
            r *= 10;
            r += (n%10);
            n = n/10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]-rev(nums[i])==nums[j]-rev(nums[j])) count++;
            }
        }
        return count;
    }
};