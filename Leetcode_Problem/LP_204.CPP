class Solution {
public:
    void fillSeive(vector<bool>& seive){
        int n = seive.size() - 1;

        for(int i = 2; i * i <= n; i++){
            if(seive[i]==true){                     
                for(int j = i * i; j <= n; j += i){
                    seive[j] = false;
                }
            }
        }
    }

    int countPrimes(int n) {

        if(n <= 2) return 0;

        vector<bool> seive(n, true);

        seive[0] = false;
        seive[1] = false;

        fillSeive(seive);

        int count = 0;

        for(int i = 2; i < n; i++){          
            if(seive[i]==true)
                count++;
        }

        return count;
    }
};