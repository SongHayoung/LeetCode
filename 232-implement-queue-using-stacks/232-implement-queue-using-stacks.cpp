class MyQueue {
    stack<int> popStack, pushStack;
public:
    MyQueue() {}
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        int res = peek();
        popStack.pop();
        return res;
    }
    
    int peek() {
        if(popStack.empty()) {
            while(!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            
        }
        return popStack.top();
    }
    
    bool empty() {
        return pushStack.empty() and popStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */