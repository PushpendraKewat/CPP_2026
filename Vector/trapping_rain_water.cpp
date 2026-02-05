#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min;

void display(vector<int>& height){
    for(int i = 0; i < height.size(); i++){
        cout << height[i] << " ";
    }
    cout << endl;
}

// Prefix Maximum (Left Max)
vector<int> prefixMaximum(vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n, -1);

    int pmax = height[0];

    for(int i = 1; i < n; i++){
        leftMax[i] = pmax;
        if(height[i] > pmax){
            pmax = height[i];
        }
    }
    return leftMax;
}

//Suffix Maximum (Right Max)
vector<int> suffixMaximum(vector<int>& height){
    int n = height.size();
    vector<int> rightMax(n, -1);

    int nmax = height[n - 1];

    for(int i = n - 2; i >= 0; i--){
        rightMax[i] = nmax;
        if(height[i] > nmax){
            nmax = height[i];
        }
    }
    return rightMax;
}

//  Trapping Rain Water 
int trappingRainWater(vector<int>& height){
    int n = height.size();
    if(n == 0) return 0;

    vector<int> leftMax = prefixMaximum(height);
    vector<int> rightMax = suffixMaximum(height);

    int water = 0;

    for(int i = 0; i < n; i++){
        int level = min(leftMax[i], rightMax[i]);
        if(level > height[i]){
            water += level - height[i];
        }
    }
    return water;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Original array: ";
    display(height);

    vector<int> leftMax = prefixMaximum(height); // leftmax
    vector<int> rightMax = suffixMaximum(height); // right max
 
    cout << "Prefix Max (Left Max): ";
    display(leftMax);

    cout << "Suffix Max (Right Max): ";
    display(rightMax);

    cout << "Trapped Water = " << trappingRainWater(height) << endl;

    return 0;
}
