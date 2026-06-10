#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void cyclesort(vector<int>& v){
    int n = v.size();
    int i = 0;

    while(i<n){
        int correctidx = v[i]-1;
        if(v[i]!=v[correctidx]){
            std::swap(v[i],v[correctidx]);
        }
        else i++;
    }

    // while(i<n){
    //     int correctidx = v[i]-1;
    //     if(i==correctidx) i++;
    //     else std::swap(v[i],v[correctidx]);
    // }
}

int main(){
    vector<int> v = {5,1,3,4,2};

    cout << "Original array: ";
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    cyclesort(v);

    cout << "Sorted array: ";
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}