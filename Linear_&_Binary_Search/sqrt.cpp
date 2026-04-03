#include<iostream>

using std::cout;
using std::endl;

int mySqrt(int x){
    int low = 0;
    int high = x;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(mid * mid == x){
            return mid;
        }
        else if(mid * mid < x){
            ans = mid;       // store possible answer
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int x = 36;
    int result = mySqrt(x);
    cout << result << endl;
    return 0;
}