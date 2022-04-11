class MyCircularQueue {
    deque<int> dq;
    int k;
public:
    MyCircularQueue(int k): k(k) {}
    
    bool enQueue(int value) {
        if(isFull()) return false;
        dq.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        dq.pop_front();
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : dq.front();
    }
    
    int Rear() {
        return isEmpty() ? -1 : dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size() == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */