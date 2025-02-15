class MRUQueue {
    int bucket;
    list<int> l;
    vector<list<int>::iterator> skip;
public:
    MRUQueue(int n) {
        bucket = sqrt(n);
        for(int i = 1; i <= n; i++) {
            l.push_back(i);
            if(((i-1) % bucket) == 0)
                skip.push_back(prev(end(l)));
        }
    }
    
    int fetch(int k) {
        k--;
        int index = k / bucket;
        auto it = skip[index];
        for(auto remainder = k % bucket; remainder > 0; remainder--)
            it++;
        l.push_back(*it);

        if(k % bucket != 0) index++;
        for(int i = index; i < skip.size(); i++)
            if(next(skip[i]) != end(l))
                skip[i] = next(skip[i]);
        
        l.erase(it);
        
        return l.back();
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */