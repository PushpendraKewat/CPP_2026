#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    int n = 5;
    vector<vector<int>> v;

    // allocate space
    for(int i = 0; i < n; i++){
        vector<int> a(i + 1);   
        v.push_back(a);
    }

    // generate Pascal triangle
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                v[i][j] = 1;
            } 
            else{
                v[i][j] = v[i-1][j] + v[i-1][j-1];
            }
        }
    }

    // print
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
