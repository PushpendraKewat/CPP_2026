#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void display(int n, vector<int>& v){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void reversePart(int i, int j, vector<int>& v){
    while(i < j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    }
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    int n = v.size();

    cout << "Original Array : ";
    display(n, v);

    int k;
    cout << "Enter K : ";
    cin >> k;

    // handle k > n
    k = k % n;

    cout << "Reverse Array by K steps : ";

    reversePart(0, n-k-1, v);
    reversePart(n-k, n-1, v);
    reversePart(0, n-1, v);

    display(n, v);
    return 0;
}
