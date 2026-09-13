// method 3 one map approach
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> m;

        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            char ch = t[i];

            if (m.find(ch) != m.end()) {
                m[ch]--;

                if (m[ch] == 0) {
                    m.erase(ch);
                }
            } else {
                return false;
            }
        }

        return m.empty();
    }
};


// method 2 two map appraoch
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for (int i = 0; i < s.length(); i++) {
            m1[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            m2[t[i]]++;
        }

        for (auto x : m1) {
            char ch = x.first;
            int freq = x.second;

            if (m2.find(ch) == m2.end() || m2[ch] != freq) {
                return false;
            }
        }

        return true;
    }
};


// method  1 sorting approach
class Solution {
public:

    bool Anagram(string s, string t){
        if(s.length()!=t.length()) return false;

        for(int i=0;i<s.length();i++){
            bool found = false;
            for(int j=0;j<t.length();j++){
                if(s[i]==t[j]){
                    found = true;
                    t[j] = '#'; // marks character as used 
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
    bool isAnagram(string s, string t) {

        // brute force apporach  
        // return Anagram(s,t); // time limit exceed
        if(s.length()!=t.length()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
    }
};