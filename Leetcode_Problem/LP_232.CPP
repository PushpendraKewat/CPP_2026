// method 2 (pop efficient)
class MyQueue {
public:
    stack<int> st;
    stack<int> helper; 
    MyQueue() {
        
    }
    
    void push(int x) {
        if (st.empty()) {
            st.push(x);
        }
        else {
            while (!st.empty()) {
                helper.push(st.top());
                st.pop();
            }

            st.push(x);  

            while (!helper.empty()) {
                st.push(helper.top());
                helper.pop();
            }
        }
    }
    
    int pop() {
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        if(st.empty()) return true;
        else return false;
    }
};

// method 1 (push efficient)
class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        helper.pop();
        
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() { // front
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st.empty()) return true;
        else return false;
    }
};
