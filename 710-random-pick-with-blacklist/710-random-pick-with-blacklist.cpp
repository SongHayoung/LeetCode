class Solution {
    int n;
    vector<int> blacklist;
    unordered_map<int, int> cache;
public:
    Solution(int n, vector<int>& b) {
        this->n = n - b.size();
        sort(b.begin(), b.end());
        this->blacklist = b;
    }
    
    int pick() {
        int pi = rand() % n;
        int key = pi;
        if(cache.count(key)) return cache[key];
        auto it = upper_bound(blacklist.begin(), blacklist.end(), pi);
        int diff = it - blacklist.begin();
        while(diff) {
            pi += diff;
            auto nit = upper_bound(it, blacklist.end(), pi);
            diff = nit - it;
            it = nit;
        }
        return cache[key] = pi;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */