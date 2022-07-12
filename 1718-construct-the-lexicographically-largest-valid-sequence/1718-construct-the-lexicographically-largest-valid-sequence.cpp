class Solution {
    bool helper(vector<int>& res, int p, int mask, int n) {
        if(p == res.size()) return true;
        else {
            if(res[p] != -1) return helper(res, p + 1, mask, n);
            for(int i = n; i >= 1; i--) {
                if(mask & (1<<i)) continue;
                if(i == 1) {
                    res[p] = 1;
                    if(helper(res, p + 1, mask | (1<<i),n)) return true;
                    res[p] = -1;
                } else {
                    if(p + i >= res.size() or res[p+i] != -1) continue;
                    res[p+i] = res[p] = i;
                    if(helper(res, p + 1, mask | (1<<i),n)) return true;                
                    res[p+i] = res[p] = -1;
                }
            }
            return false;
        }
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(n * 2 - 1,-1);
        helper(res,0,0,n);
        return res;
    }
};