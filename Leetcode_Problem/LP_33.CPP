#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int pivot = -1;

        //  find pivot
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

        //  if nums not rotated
        if(pivot == -1){
            low = 0;
            high = n - 1;

            while(low <= high){
                int mid = low + (high - low) / 2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
            return -1;
        }

        //  choose correct half
        if(target >= nums[0] && target <= nums[pivot-1]){
            low = 0;
            high = pivot - 1;
        } 
        else{ // right 
            low = pivot;
            high = n - 1;
        }

        //  binary search
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return -1; //  if not found
    }
};
