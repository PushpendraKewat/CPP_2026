#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){

    vector<int> v = {5,3,10};

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    float kmin = (float)INT_MIN;
    float kmax = (float)INT_MAX;

    bool flag = true;

    for(int i=0; i<v.size()-1; i++){

        // For decreasing pair
        if(v[i] >= v[i+1]){
            kmin = std::max(kmin, (v[i] + v[i+1]) / 2.0f);
        }

        // For increasing pair
        else{
            kmax = std::min(kmax, (v[i] + v[i+1]) / 2.0f);
        }

        if(kmin > kmax){
            flag = false;
            break;
        }
    }

    if(flag == false){
        cout << -1;
    }
    else{
        cout << "Range of k is : ["
             << kmin << " , "
             << (int)kmax << "]";
    }

    return 0;
}