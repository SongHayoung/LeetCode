class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    void pop() {
        while(pq.size() > k) pq.pop();
    }
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for(auto& n : nums) pq.push(n);
        pop();
    }
    
    int add(int val) {
        pq.push(val);
        pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */