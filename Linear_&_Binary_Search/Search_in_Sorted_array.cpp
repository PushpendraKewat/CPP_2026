#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void search_rotated_sorted(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int pivot = -1;

    // 🔹 find pivot
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(mid > 0 && nums[mid] < nums[mid-1]){
            pivot = mid;
            break;
        }
        else if(mid < n-1 && nums[mid] > nums[mid+1]){
            pivot = mid + 1;
            break;
        }
        else if(nums[mid] >= nums[low]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    int ans = -1;

    // 🔹 if NOT rotated → simple binary search
    if(pivot == -1){
        low = 0;
        high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
    }
    else{
        // 🔹 decide correct half
        if(target >= nums[0] && target <= nums[pivot-1]){
            low = 0;
            high = pivot - 1;
        }
        else{
            low = pivot;
            high = n - 1;
        }

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
    }

    cout << ans << endl;
}

int main(){
    vector<int> v = {1,3,4,8,20,28,33}; // not rotated
    int target = 8;

    search_rotated_sorted(v,target);
    return 0;
}