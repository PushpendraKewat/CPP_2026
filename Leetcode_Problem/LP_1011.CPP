#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    bool check(int mid, vector<int>& weights, int days){
        int d = 1;      // days used
        int load = 0;

        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] <= mid){
                load += weights[i];
            } else {
                d++;                // new day
                load = weights[i];
            }
        }

        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxi = std::INT_MIN;

        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];               
            maxi = std::max(maxi, weights[i]);   
        }

        int low = maxi;     // max element
        int high = sum;     // total sum
        int mincapacity = sum;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(mid, weights, days)){
                mincapacity = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return mincapacity;
    }
};