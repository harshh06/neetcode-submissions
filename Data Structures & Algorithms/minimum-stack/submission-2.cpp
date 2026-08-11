class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int, int>> st;

    void push(int val) {
        int mn=min(st.empty()?INT_MAX:st.top().second,val) ;   
        st.push({val, mn});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
