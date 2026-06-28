class Solution {
public:
    bool isPrime(int n){
        if(n == 1) return false;

        for(int i = 2; i * i <= n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }

    vector<int> primefactor(int n){
        vector<int> ans;

        for(int i = 2; i * i <= n; i++){
            while(n % i == 0){
                ans.push_back(i);
                n /= i;
            }
        }

        if(n > 1)
            ans.push_back(n);

        return ans;
    }

    int smallestValue(int n) {
        while(!isPrime(n)){
            int sum = 0;

            vector<int> ans = primefactor(n);

            for(int i = 0; i < ans.size(); i++){
                sum += ans[i];
            }

            if(sum == n)
                break;

            n = sum;
        }

        return n;
    }
};