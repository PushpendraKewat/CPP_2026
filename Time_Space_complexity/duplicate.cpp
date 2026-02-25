#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

void bruteforce(vector<int>& v){
    bool found = false;

    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]==v[j]){
                cout<<"duplicate element : "<<v[i]<<endl;
                found = true;
                break;
            }
        }
        if(found) break; // break outer loop
    }
    if(!found) cout<<"No duplicate";
}

void extraspace(vector<int>& v){
    int n = v.size();
    vector<int> extra(n,0);

    for(int i=0;i<n;i++){
        int val = v[i];

        if(extra[val] == 1){
            cout<<"duplicate element : "<<val<<endl;
            return;
        }

        extra[val] = 1;
    }

    cout<<"No duplicate";
}

void mathapproach(vector<int>& v){
    int n = v.size() - 1;  // because size is n+1
    int sum = 0;

    for(int i=0;i<v.size();i++){
        sum += v[i];
    }

    int expected = n * (n + 1) / 2;

    int duplicate = sum - expected;

    cout<<"duplicate element : "<<duplicate;
}
void optimize1(vector<int>& v){
    std::sort(v.begin(),v.end());
     bool found = false;

    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]){
            cout<<"\nDuplicate element in array : "<<v[i];
            found = true;
            break;
        }
    }

    if(!found){
        cout<<"\nNo duplicate element found";
    }
}
int main(){
    vector<int> v = {6,1,2,4,3,2,7,5};

    cout<<"Original array : ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // bruteforce(v);
    // extraspace(v);
    mathapproach(v);
    // optimize1(v);

    return 0;
}