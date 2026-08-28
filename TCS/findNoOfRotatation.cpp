#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

int findRotation(vector<int>& v){
    // linear search approach
    int n = v.size();

    // if array is sorted
    if(v[0] <= v[n - 1]){
        return 0;
    }

    int minidx = 0;
    for(int i = 1; i < v.size(); i++){
        if(v[i] < v[minidx]){
            minidx = i;
        }
    }
    return minidx;
}

int findRotationBinary(vector<int>& v){
    int n = v.size();
    int low = 0;
    int high = n-1;

    // if array is already sorted
    if(v[low] <= v[high]){
        return 0;
    }

    while(low < high){
        int mid = low + (high - low) / 2;

        if(v[mid] > v[high]){ // minimum lies in right half
            low = mid + 1;
        }
        else{ // minimum lies in left half (including mid)
            high = mid;
        }
    }

    return low;
}

int main(){
    vector<int> v = {18,15,1,2,3,5};

    cout<<"Before k rotation \n";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;
    cout<<"no of rotation : "<<findRotation(v);
    cout<<"\nno of rotation (using binary search):"<<findRotationBinary(v);

    return 0;
}