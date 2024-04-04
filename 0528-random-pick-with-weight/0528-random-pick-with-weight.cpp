class Solution {
    vector<int> pre;
public:
    Solution(vector<int>& w) {
        for(auto& x : w) {
            pre.push_back(x + (pre.size() ? pre.back() : 0));
        }
    }
    
    int pickIndex() {
        int mod = pre.back();
        int who = rand() % mod;
        int it = upper_bound(begin(pre),end(pre),who) - begin(pre);
        return max(0,it);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */