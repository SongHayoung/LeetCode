class Solution {
    int m, n, len;
    unordered_map<int, int> h;
public:
    Solution(int m, int n):m(m), n(n), len(m * n) {
    }

    vector<int> flip() {
        int r = rand() % len--;
        int i = h.count(r) ? h[r] : r;
        h[r] = h.count(len) ? h[len] : len;
        
        return {i / n, i % n};
    }

    void reset() {
        len = m * n;
        h = unordered_map<int,int>();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */