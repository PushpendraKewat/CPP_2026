#include <iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // binary search and max element
        int mini = 1; // minimum speed;
        int maxi = INT_MIN; // max speed
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        int low = mini;
        int high = maxi;

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long hours = 0;

            // calculate total hours needed at speed = mid
            for(int i = 0; i < piles.size(); i++){
                hours += (piles[i] + mid - 1) / mid; // ceil division
            }

            if(hours <= h){
                high = mid - 1;   // try smaller speed
            }
            else{
                low = mid + 1;    // need higher speed
            }
        }
        return low;
    }
};