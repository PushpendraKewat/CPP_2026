#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void heapifyAlgorithm(int i, vector<int>& v){
    int n = v.size() - 1;

    while(true){
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left > n) break;

        if(right > n){
            if(v[i] > v[left]){
                std::swap(v[i], v[left]);
                i = left;
            }
            break;
        }

        if(v[left] < v[right]){
            if(v[i] > v[left]){
                std::swap(v[i], v[left]);
                i = left;
            }
            else{
                break;
            }
        }
        else{
            if(v[i] > v[right]){
                std::swap(v[i], v[right]);
                i = right;
            }
            else{
                break;
            }
        }
    }
}

int main(){
    vector<int> v = {-1,10,2,14,11,1,4};
    int n = v.size()-1;
    
    cout<<"before heapify alforithm :";
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;

    for(int i = n/2;i>=1;i--){
        heapifyAlgorithm(i,v);
    }

    cout<<"after heapify alforithm :";
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
   
    return 0;
}