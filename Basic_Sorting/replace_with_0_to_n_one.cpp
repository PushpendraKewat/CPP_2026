#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    vector<int> v = {19,12,23,8,16};
    int n = v.size();

    vector<int> isvisited(n,0);

    for(int i = 0; i < n; i++){
        int mini = INT_MAX;
        int minidx = -1;

        for(int j = 0; j < n; j++){
            if(isvisited[j]) continue;

            if(v[j] < mini){
                mini = v[j];
                minidx = j;
            }
        }

        cout << minidx << " ";   // print index instead of value
        isvisited[minidx] = 1;
    }

    return 0;
}