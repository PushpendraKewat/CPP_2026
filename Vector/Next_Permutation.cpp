#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void mySwap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void myReverse(int start, vector<int>& nums){
    int i = start;
    int j = nums.size() - 1;

    while(i < j){
        mySwap(nums[i], nums[j]);
        i++;
        j--;
    }
}

void nextPermutation(vector<int>& nums){
    int n = nums.size();
    int pivot = -1;
    for(int i = n - 2; i >= 0; i--){
        if(nums[i] < nums[i + 1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        myReverse(0, nums);
        return;
    }

    for(int j = n - 1; j > pivot; j--){
        if(nums[j] > nums[pivot]){
            mySwap(nums[j], nums[pivot]);
            break;
        }
    }

    myReverse(pivot + 1, nums);
}

void display(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {1, 4, 2, 3};

    cout << "Original array: ";
    display(nums);

    nextPermutation(nums);

    cout << "Next permutation: ";
    display(nums);

    return 0;
}
