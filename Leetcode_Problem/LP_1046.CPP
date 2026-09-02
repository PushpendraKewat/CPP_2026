// method 2 chatgpt solution
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones[i]);
        }

        int ans = 0;

        while(maxHeap.size() > 1) {
            int x = maxHeap.top(); // first max weight
            maxHeap.pop();

            int y = maxHeap.top(); // second max weight
            maxHeap.pop();

            if(x != y) {
                ans = x - y;
                maxHeap.push(ans);
            }
        }

        if(!maxHeap.empty()) return maxHeap.top();
        else return 0;
    }
};

// method 1
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones[i]);
        }

        // after push element in heap max weight in is top
        // now store heap.top() and minus with new heap.top()
        int ans = 0;

        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();

            if (x == maxHeap.top()) {
                // destroy both weight
                maxHeap.pop();
            } else {
                ans = x - maxHeap.top();
                maxHeap.pop();
                maxHeap.push(ans);
            }
        }

        if (!maxHeap.empty()) return maxHeap.top();
        else return 0;
    }
};