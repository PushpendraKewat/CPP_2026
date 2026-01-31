#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    // vector<int> v;
    
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << " ";
    // }

    vector<int> v1 = {1,2,3,4};
    vector<int> v2(5);        // size 5, all 0
    vector<int> v3(5, 10);    // size 5, all 10

    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;

     for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
    }
    cout<<endl;

    return 0;
}