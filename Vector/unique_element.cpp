#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

void display(vector<int>& v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

// int findUnique(vector<int>& arr) {
//     int n = arr.size();

//     for (int i = 0; i < n; i++) {
//         int count = 0;

//         for (int j = 0; j < n; j++) {
//             if (arr[i] == arr[j]) {
//                 count++;
//             }
//         }

//         if (count == 1) {
//             return arr[i];
//         }
//     }
//     return -1;
// }


int findUnique(vector<int>& arr) {
    int ans = 0;
    for (int x : arr) {
        ans ^= x;
    }
    return ans;
}

int main(){
    vector<int> v {0,1,3,3,1,0,2};
    display(v);

    cout << "Unique element: " << findUnique(v) << endl;
    return 0;
}
