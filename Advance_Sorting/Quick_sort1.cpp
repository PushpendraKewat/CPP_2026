#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

int partition(vector<int>& v, int si, int ei){
    int pivot = v[ei];
    int i = si - 1;
    int j = si;

    while(j < ei){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
        j++;
    }

    i++;
    swap(v[i], v[ei]);

    return i;
}

void quicksort(vector<int>& v, int si, int ei){
    if(si >= ei) return;

    int pivotidx = partition(v, si, ei);

    quicksort(v, si, pivotidx - 1);
    quicksort(v, pivotidx + 1, ei);
}

int main(){
    vector<int> v = {5,1,8,2,7,6,3,4};

    cout << "Original Array: ";
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    quicksort(v, 0, v.size() - 1);

    cout << "Sorted Array: ";
    for(int x : v){
        cout << x << " ";
    }

    return 0;
}