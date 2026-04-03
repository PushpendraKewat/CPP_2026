#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// void fo(vector<int>&v,int x){
//     for(int i=0;i<v.size();i++){
//         if(v[i]==x){
//             cout<<"[Linear] First occurrence of "<<x<<" is at index: "<<i<<endl;
//             return;
//         }
//     }
//     cout<<"-1";
// }

int firstOccurrence(vector<int>& v, int x){

    int low = 0, high = v.size() - 1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(v[mid] == x){
            ans = mid;
            high = mid - 1; // move left
        }
        else if(v[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}


int main(){
    vector<int> v = {1,2,2,3,3,3,3,4,4,5,8,9};
    int x = 3;
    // fo(v,x);

    int idx = firstOccurrence(v,x);

    if(idx != -1){
        cout<<"[Binary] First occurrence of "<<x<<" is at index: "<<idx<<endl;
    } else {
        cout<<"-1"<<endl;
    }


    return 0;
}