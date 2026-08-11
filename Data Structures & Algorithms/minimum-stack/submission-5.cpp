class MinStack {
public:
    MinStack() {
        
    }

    stack<pair<int, int>> st;
    int mn=INT_MAX;
    
    void push(int val) {
        mn= min(mn, val);
        st.push({val, mn});   
    }
    
    void pop() {
        st.pop();
        mn=st.empty()?INT_MAX: st.top().second;
    } 
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
