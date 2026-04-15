#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    bool check(long long mid, vector<int>& time, int totalTrips){
        long long trips = 0;

        for(int i = 0; i < time.size(); i++){
            trips += mid / time[i];

            if(trips >= totalTrips) return true;
        }

        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;

        long long mx = INT_MIN;
        for(int i = 0; i < time.size(); i++){
            mx = max(mx, (long long)time[i]);
        }

        long long high = 1LL * mx * totalTrips;
        long long ans = -1;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(check(mid, time, totalTrips)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};