// method 2 set approach
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int count = 0;

        for(int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());

            if(s.find(rev) != s.end()) {
                count++;
            }
            else {
                s.insert(words[i]);
            }
        }

        return count;
    }
};


// method 1 basic method 
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0;i<n;i++){
            string rev = words[i];
            reverse(rev.begin(),rev.end());
            for(int j=i+1;j<n;j++){
                if(rev==words[j]) count++;
            }
        }
        return count;
    }
};