#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int peakindex(vector<int>& v){
    int low = 0;
    int high = v.size() - 1;

    while(low < high){
        int mid = low + (high - low) / 2;

        if(v[mid] < v[mid + 1]){
            low = mid + 1;  
        } else {
            high = mid;
        }
    }
    return low;
}

int main(){
    vector<int> v = {1,3,5,4,3,2,0};
    int result = peakindex(v);
    cout<<"Peak index in array :"<<result;
    return 0;
}