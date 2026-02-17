#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void display(vector<vector<int>>& v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int m,n;
    cout<<"Enter the rows and columns of matrix :";
    cin>>m>>n;
    vector<vector<int>> v;
    v.push_back({0, 0, 1, 1});
    v.push_back({1, 0, 1, 0});
    v.push_back({1, 1, 0, 0});

    display(v);
    return 0;
}