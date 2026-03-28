#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    vector<int> v = {1,2,4,6,7,9,15,18,21,24};
    int target = 9;

    int low = 0;
    int high = v.size() - 1;
    bool flag = false; 

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(v[mid] == target){
            cout << "Found " << target << " at index: " << mid << endl;
            flag = true;
            break;
        }
        else if(v[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    if(!flag){
        cout << "Not found" << endl;
    }

    return 0;
}