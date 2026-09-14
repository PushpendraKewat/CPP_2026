class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;

        unordered_map<int,int> m; // value freq
        for(int ele : digits){
            m[ele]++;
        }

        for(int i = 100; i <= 999; i++){
            if(i % 2 != 0) continue;

            int x = i;
            int a = x % 10;
            x = x / 10;
            int b = x % 10;
            x = x / 10;
            int c = x % 10;
            x = x / 10;

            if(m[a] == 0){
                continue;
            }
            else{ // a is in map
                m[a]--; // use a

                if(m[b] == 0){
                    m[a]++;
                    continue;
                }
                else{ // b is in map
                    m[b]--; // use b

                    if(m[c] == 0){
                        m[a]++;
                        m[b]++;
                        continue;
                    }
                    else{ // c is in map
                        ans.push_back(i);
                    }

                    m[b]++; // restore b
                }

                m[a]++; // restore a
            }
        }

        return ans;
    }
};