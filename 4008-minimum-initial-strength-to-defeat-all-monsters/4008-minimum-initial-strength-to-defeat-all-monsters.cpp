
class Solution {
    bool helper(vector<int>& A, vector<long long>& p, long long s) {
        for(int i = 0; i < A.size(); i++) {
            if(A[i] > s + p[i]) return false;
            s = max(0ll, s - A[i]);
        }
        return true;
    }
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        vector<long long> pre(monsters.size() + 1);
        for(auto& b : boosts) {
            pre[b[0]] += b[2];
            pre[b[1] + 1] -= b[2];
        }
        for(int i = 1; i < pre.size(); i++) pre[i] += pre[i-1];
        long long l = 0, r = 1e18, res = r;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(monsters, pre, m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};