class CustomStack {
    vector<pair<int,int>> st;
    int ma = 0;
public:
    CustomStack(int maxSize):ma(maxSize) {
        
    }
    
    void push(int x) {
        if(ma == st.size()) return;
        st.push_back({x,0});
    }
    
    int pop() {
        if(st.size() == 0) return -1;
        auto [val,add] = st.back(); st.pop_back();
        if(st.size()) st.back().second += add;
        return val + add;
    }
    
    void increment(int k, int val) {
        k = min(k - 1, (int)st.size() - 1);
        if(k >= 0) st[k].second += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */