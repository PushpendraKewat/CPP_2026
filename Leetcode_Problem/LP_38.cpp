#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string str = countAndSay(n - 1);

        string s = "";
        int freq = 1;
        char ch = str[0];

        for(int i = 1; i < str.length(); i++){
            char dh = str[i];

            if(ch == dh){
                freq++;
            }
            else{
                s += to_string(freq);
                s += ch;

                freq = 1;
                ch = dh;
            }
        }

        // last group
        s += to_string(freq);
        s += ch;
        return s;
    }
};