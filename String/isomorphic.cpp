#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(){

    string s = "egg";
    string t = "add";

    if(s.size() != t.size()){
        cout << "false";
        return 0;
    }

    vector<int> posS(256, 0);
    vector<int> posT(256, 0);

    for(int i = 0; i < s.size(); i++){

        if(posS[s[i]] != posT[t[i]]){
            cout << "false";
            return 0;
        }

        // store last seen position (i+1 because default is 0)
        posS[s[i]] = i + 1;
        posT[t[i]] = i + 1;
    }

    cout << "true";
    return 0;
}