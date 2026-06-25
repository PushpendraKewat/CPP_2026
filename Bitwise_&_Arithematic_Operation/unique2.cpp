#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> uniqueUsingSort(vector<int>& v){
    vector<int> ans;

    vector<int> temp = v;
    sort(temp.begin(), temp.end());

    for(int i = 0; i < temp.size(); ){
        int count = 1;

        while(i + count < temp.size() &&
              temp[i] == temp[i + count]){
            count++;
        }

        if(count == 1){
            ans.push_back(temp[i]);
        }

        i += count;
    }

    return ans;
}

vector<int> uniqueUsingXOR(vector<int>& v){
    int xorAll = 0;

    for(int num : v){
        xorAll ^= num;
    }

    int mask = xorAll & (-xorAll);

    int a = 0;
    int b = 0;

    for(int num : v){
        if(num & mask){
            a ^= num;
        }
        else{
            b ^= num;
        }
    }

    return {a, b};
}

int main(){
    vector<int> v = {2,1,3,2,1,5,5,6,3,9};

    vector<int> ans1 = uniqueUsingSort(v);
    vector<int> ans2 = uniqueUsingXOR(v);

    cout << "Using Sort: ";
    for(int x : ans1){
        cout << x << " ";
    }

    cout << "\nUsing XOR: ";
    for(int x : ans2){
        cout << x << " ";
    }

    return 0;
}