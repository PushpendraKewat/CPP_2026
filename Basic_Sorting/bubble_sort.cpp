#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Normal Bubble Sort
void bubbleSort(vector<int>& v){
    int n = v.size();

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                std::swap(v[j], v[j+1]);
            }
        }
    }
}

// Optimized Bubble Sort
void bubbleSortOptimized(vector<int>& v){
    int n = v.size();

    for(int i = 0; i < n-1; i++){
        bool flag = false;

        for(int j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                std::swap(v[j], v[j+1]);
                flag = true;
            }
        }
        if(!flag) break; // already sorted
    }
}

// Display function
void display(vector<int>& v){
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {5, 3, 1, 4, 2};
    vector<int> v2 = v; // copy for optimized version

    cout << "Original array: ";
    display(v);

    bubbleSort(v);
    cout << "Sorted (Normal Bubble): ";
    display(v);

    bubbleSortOptimized(v2);
    cout << "Sorted (Optimized Bubble): ";
    display(v2);

    return 0;
}