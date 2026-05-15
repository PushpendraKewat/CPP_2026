#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

int merge(vector<int>& arr, int low, int mid, int high){

    vector<int> temp;

    int left = low;
    int right = mid + 1;

    int count = 0;

    while(left <= mid && right <= high){

        if(arr[left] <= arr[right]){

            temp.push_back(arr[left]);
            left++;
        }
        else{

            // Inversion found
            count += (mid - left + 1);

            // Print pairs
            for(int i = left; i <= mid; i++){
                cout << "(" << arr[i] << "," << arr[right] << ")" << endl;
            }

            temp.push_back(arr[right]);
            right++;
        }
    }

    // Remaining left elements
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    // Remaining right elements
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }

    return count;
}

int mergesort(vector<int>& arr, int low, int high){

    int count = 0;

    if(low >= high) return count;

    int mid = low + (high - low)/2;

    // Left half
    count += mergesort(arr, low, mid);

    // Right half
    count += mergesort(arr, mid + 1, high);

    // Merge step
    count += merge(arr, low, mid, high);

    return count;
}

int main(){

    vector<int> arr = {5,2,8,1};

    int ans = mergesort(arr, 0, arr.size()-1);

    cout << "Total Inversions = " << ans << endl;

    return 0;
}