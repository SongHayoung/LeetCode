class LUPrefix {
    unordered_set<int> us;
    int x;
public:
    LUPrefix(int n):x(0) {
        
    }
    
    void upload(int video) {
        us.insert(video);
        while(us.count(x + 1)) {
            x++;
            us.erase(x);
        }
    }
    
    int longest() {
        return x;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */