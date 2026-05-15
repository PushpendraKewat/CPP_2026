#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void merge(vector<int>& arr, int low, int mid, int high){

    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while(left <= mid && right <= high){

        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
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
}

void mergesort(vector<int>& arr, int low, int high){

    if(low >= high) return;

    int mid = low + (high - low)/2;

    // Left half
    mergesort(arr, low, mid);

    // Right half
    mergesort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main(){

    vector<int> arr = {5,2,8,1,3};

    cout << "Original Array: ";

    for(int x : arr){
        cout << x << " ";
    }

    cout << endl;

    mergesort(arr, 0, arr.size()-1);

    cout << "Sorted Array: ";

    for(int x : arr){
        cout << x << " ";
    }

    return 0;
}