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
    string s = "raghav is a math teacher He is a DSA mentor as well";
    std::stringstream ss(s);
    string temp;
    vector<string> v;

    while(ss >> temp){
        v.push_back(temp);
    }

    std::sort(v.begin(), v.end());

    int mx = 1;
    int count = 1;

    // First pass → find max frequency
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i-1]){
            count++;
        }
        else{
            count = 1;
        }
        mx = std::max(mx, count);
    }

    // Second pass → print all words with max frequency
    cout << "Most occurring word(s):\n";

    count = 1;
    if(mx == 1){
        cout << "All words occur once\n";
        return 0;
    }

    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i-1]){
            count++;
        }
        else{
            if(count == mx){
                cout << v[i-1] << " -> " << mx << endl;
            }
            count = 1;
        }
    }

    // last group check
    if(count == mx){
        cout << v[v.size()-1] << " -> " << mx << endl;
    }

    return 0;
}