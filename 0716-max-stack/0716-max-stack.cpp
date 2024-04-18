class MaxStack {
    list<int> li;
    map<int, vector<list<int>::iterator>> it;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        li.push_back(x);
        it[x].push_back(prev(end(li)));
    }
    
    int pop() {
        int val = *prev(end(li));
        it[val].pop_back();
        if(it[val].size() == 0) it.erase(val);
        li.pop_back();
        return val;
    }
    
    int top() {
        return *prev(end(li));
    }
    
    int peekMax() {
        return prev(end(it))->first;
    }
    
    int popMax() {
        auto iter = prev(end(it))->second.back();
        int res = *iter;
        it[res].pop_back();
        if(it[res].size() == 0) it.erase(res);
        li.erase(iter);
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