#include<iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(mid * mid == x){
                return mid;
            }
            else if(mid * mid > x){
                high = mid - 1;
            }
            else{
                ans = mid;        // store possible answer
                low = mid + 1;    // move right ✅
            }
        }
        return ans;
    }
};