#include<iostream>
#include<queue>

using std::cout;
using std::endl;
using std::queue;

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.front()<<endl;
    return 0;
}