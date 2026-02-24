#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main(){
    vector<string> v = {"0123","0023","456","0182","2901"};
    int mx = std::stoi(v[0]);
    for(int i=1;i<v.size();i++){
        int n = std::stoi(v[i]);
        if(mx < n){
            mx = n;
        }
    }
    cout<<"max in string :"<<mx;
    return 0;
}