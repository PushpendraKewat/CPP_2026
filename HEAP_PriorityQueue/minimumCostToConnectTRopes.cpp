#include<iostream>
#include<queue>
#include<vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;
using std::greater;

int minimumCost(vector<int>& v){
    priority_queue<int,vector<int>,greater<int>> minHeap;

    for(int i=0;i<v.size();i++){
        minHeap.push(v[i]);
    }
    int cost = 0;
    while(minHeap.size() > 1){
        int x = minHeap.top(); // first min
        minHeap.pop();
        int y = minHeap.top(); // second min
        minHeap.pop();
        int sum = x+y;
        cost += sum;
        minHeap.push(sum);
    }
    return cost;
}

int main(){
    vector<int> v = {2,7,4,1,8};
    cout<<"minimum cost to connect to all ropes :"<<minimumCost(v);
    return 0;
}