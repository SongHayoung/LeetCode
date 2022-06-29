class MaxStack {
    map<int, vector<int>> ms;
    vector<int> st;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        ms[x].push_back(st.size());
        st.push_back(x);
    }
    
    int pop() {
        while(st.back() == INT_MIN) st.pop_back();
        int res = st.back(); st.pop_back();
        ms[res].pop_back();
        if(ms[res].empty())
            ms.erase(res);
        return res;
    }
    
    int top() {
        while(st.back() == INT_MIN) st.pop_back();
        return st.back();
    }
    
    int peekMax() {
        return ms.rbegin()->first;
    }
    
    int popMax() {
        auto it = ms.rbegin();
        st[it->second.back()] = INT_MIN;
        it->second.pop_back();
        int res = it->first;
        if(it->second.empty()) ms.erase(it->first);
        return res;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */