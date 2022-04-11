class Solution {
    map<int, int> m;
    int tot = 0;
public:
    Solution(vector<int>& w) {
        for(int i = 0; i < w.size(); i++) {
            m[tot] = i;
            tot += w[i];
        }
    }

    int pickIndex() {
        int num = rand() % tot;
        return prev(m.upper_bound(num))->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */