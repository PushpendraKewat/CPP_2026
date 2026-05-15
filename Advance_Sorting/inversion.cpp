#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void inversion(vector<int>& v){ // brute force

    int count = 0;

    for(int i = 0; i < v.size()-1; i++){
        for(int j = i+1; j < v.size(); j++){
            if(v[i] > v[j]){
                cout << "(" << v[i] << "," << v[j] << ")" << endl;
                count++;
            }
        }
    }
    cout << "Total Inversions = " << count;
}

int main(){
    vector<int> v = {5,1,8,2,3};

    cout<<"original array :";
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    inversion(v);
    return 0;
}