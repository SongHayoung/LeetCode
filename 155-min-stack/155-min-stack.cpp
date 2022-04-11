class MinStack {
    vector<int> st;
    vector<int> mi;
public:
    MinStack() {}
    
    void push(int val) {
        if(st.empty() or st[mi.back()] > val) {
            mi.push_back(st.size());
        }
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
        if(mi.back() == st.size())
            mi.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return st[mi.back()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */