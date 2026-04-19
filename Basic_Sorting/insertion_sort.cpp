#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void insertion_sort(vector<int>& v){
    for(int i = 1; i < v.size(); i++){
        int j = i;
        while(j > 0 && v[j] < v[j-1]){
            std::swap(v[j], v[j-1]);
            j--;
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
    insertion_sort(v);
    display(v);
    return 0;
}