#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main(){

    // ["folwer","flow","flight"]
    vector<string> strs = {"flower","flow","flight"};
    
    // normal print
    cout<<"Original string : ";
    for(int i=0;i<strs.size();i++){
        cout<<strs[i]<<" ";
    }
    // string after sorting 
    cout<<"\nstring after sorting : ";
    sort(strs.begin(),strs.end());
    for(int i=0;i<strs.size();i++){
        cout<<strs[i]<<" ";
    }

    // longest common prefix
    string first = strs[0];
    string last =  strs[strs.size()-1];
    string ans = "";
    int i = 0;
    while(i < first.size() && i < last.size()){
        if(first[i]==last[i]){
            ans += first[i];
        }
        else break;
        i++;
    }

    cout << "\nLongest Common Prefix : " << ans;

    return 0;
}