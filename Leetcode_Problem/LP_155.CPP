// method 4 tc and sc = o(1)
class MinStack {
public:
    stack<long long> st;
    long long mn;

    MinStack() {
        mn = LLONG_MAX;
    }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mn = value;
        }
        else if (value >= mn) {
            st.push(value);
        }
        else { // value < mn
            st.push(2LL * value - mn); // encoded value
            mn = value;
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() < mn) { // encoded value
            mn = 2LL * mn - st.top(); // restore previous minimum
        }

        st.pop();
    }

    int top() {
        if (st.top() >= mn)
            return st.top();

        // Encoded value: actual top is the current minimum
        return mn;
    }

    int getMin() {
        return mn;
    }
};

// method 3 (vector) bad approacj
class MinStack {
public:
    vector<int> v;
    MinStack() {
        
    }
    
    void push(int value) {
        v.push_back(value);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        int mn = v[0];
        for(int i=1;i<v.size();i++){
            mn = min(mn,v[i]);
        }
        return mn;
    }
};

// method 2 (using extra stack)
class MinStack {
public:
    stack<int> st;
    stack<int> helper;

    MinStack() {
    }

    void push(int value) {
        st.push(value);

        if (helper.empty() || value <= helper.top()) {
            helper.push(value);
        } else {
            helper.push(helper.top());
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
            helper.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return helper.top();
    }
};


// method 1 (brute force)
class MinStack {
public:
    stack<int> st;

    MinStack() {
    }

    void push(int val) {
        st.push(val);
    }

    void pop() {
        if (!st.empty())
            st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        stack<int> temp = st;      // Copy the original stack
        int mn = temp.top();

        while (!temp.empty()) {
            mn = min(mn, temp.top());
            temp.pop();
        }

        return mn;
    }
};