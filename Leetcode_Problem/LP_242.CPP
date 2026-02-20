#include<iostream>
#include<string>
#include<algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;

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