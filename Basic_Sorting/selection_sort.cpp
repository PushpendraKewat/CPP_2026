#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void selection_sort2(vector<int>& v){
    int n = v.size();

    for(int i = 0; i < n - 1; i++){
        int min = INT_MAX;
        int min_idx = -1;

        for(int j = i; j < n; j++){
            if(v[j] < min){
                min = v[j];
                min_idx = j;
            }
        }

        std::swap(v[i], v[min_idx]); 
    }
}

void selection_sort(vector<int>& v) {
    int n = v.size();

    // One by one move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Assume the current position is the minimum
        int min_idx = i;

        // Step 1: Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }

        // Step 2: Swap the found minimum element with the first element
        if (min_idx != i) {
            std::swap(v[min_idx], v[i]);
        }
    }
}

void display(vector<int>& v){
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
}


int main(){
    vector<int> v = {5,3,1,4,2};
    cout<<"Original aray :";
    display(v);
    cout<<"Selection Sort :";
    selection_sort(v);
    display(v);
    return 0;
}