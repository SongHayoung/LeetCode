class MyCircularDeque {
    vector<int> A;
    int st = 0, ed = 1;
public:
    MyCircularDeque(int k) {
        A = vector<int>(k + 2);
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        A[st--] = value;
        st = (st + A.size()) % A.size();
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(isEmpty()) {
            return insertFront(value);
        }
        A[ed++] = value;
        ed %= A.size();
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        st = (st + 1) % A.size();
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        
        ed = (ed - 1 + A.size()) % A.size();
        return true;
        
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        
        return A[(st + 1) % A.size()];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        
        return A[(ed - 1 + A.size()) % A.size()];
    }
    
    bool isEmpty() {
        return ed == (st + 1) % A.size();
    }
    
    bool isFull() {
        return (ed + 1) % A.size() == st;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */