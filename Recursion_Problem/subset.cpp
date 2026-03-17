#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void subset(string ans, string original){
    if(original.length() == 0){
        cout << ans << endl;
        return;
    }
    char ch = original[0];
    // include
    subset(ans+ch,original.substr(1));
    // ecclude
    subset(ans,original.substr(1));
}

void subset2(string ans, string original, int idx){
    if(idx == original.length()){   
        cout << ans << endl;
        return;
    }

    char ch = original[idx];
    // include
    subset2(ans + ch, original, idx + 1);
    // exclude
    subset2(ans, original, idx + 1);
}

void storesubset(string ans, string original, vector<string>& v){
    if(original==""){
        v.push_back(ans);
        return;
    }
    char ch = original[0];
    //exclue
    storesubset(ans,original.substr(1),v);
    // include
    storesubset(ans+ch,original.substr(1),v);
}

int main(){
    string str = "abc";
    vector<string> v;
    // subset("",str);
    // subset2("",str,0);
    storesubset("",str,v);
    for(string e : v){
        cout<<e<<endl;
    }
    return 0;
}