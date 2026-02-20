#include<iostream>
#include<string>
#include<algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string s = "raghav";

    int mxcount = 0;
    char maxChar = s[0];

    for(int i = 0; i < s.length(); i++){
        int count = 0;
        for(int j = 0; j < s.length(); j++){
            if(s[i] == s[j]){
                count++;
            }
        }
        if(count > mxcount){
            mxcount = count;
            maxChar = s[i];   // store the character
        }
    }

    cout << "Most occurring character : " << maxChar << endl;
    cout << "Frequency : " << mxcount;

    return 0;
}