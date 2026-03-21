#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void generate(vector<int>& arr, int start, int end){
    int n = arr.size();

    if(end == n) return;

    // print subarray
    for(int i = start; i <= end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    generate(arr, start, end + 1);
}

void subarray(vector<int>& arr){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        generate(arr, i, i);
        cout << endl;
    }
}

int main(){
    vector<int> v = {1,2,3,4};
    subarray(v);
    return 0;
}