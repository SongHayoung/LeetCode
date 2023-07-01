class Solution {
    int dp[1<<10][10];
    vector<int> comb(int mask, int n) {
        vector<int> cand;
        for(int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            cand.push_back(i);
        }
        vector<int> res;
        for(int i = 1; i < (1<<cand.size()); i++) {
            int m = 0;
            for(int j = 0; j < cand.size(); j++) {
                if(i & (1<<j)) {
                    m |= 1<<(cand[j]);
                }
            }
            res.push_back(m);
        }
        return res;
    }
    int helper(int mask, int now, int k, vector<int>& A) {
        if(mask == (1<<A.size()) - 1) {
            if(now == k) return 0;
            return INT_MAX;
        }
        if(now == k) return INT_MAX;
        if(dp[mask][now] != -1) return dp[mask][now];
        int& res = dp[mask][now] = INT_MAX;
        auto combs = comb(mask, A.size());
        for(auto& c : combs) {
            int cost = 0;
            for(int i = 0; i < A.size(); i++) {
                if(c & (1<<i)) cost += A[i];
            }
            res = min(res, max(cost, helper(mask | c, now + 1, k , A)));
        }
        return res;
    }
public:
    int distributeCookies(vector<int>& A, int k) {
        memset(dp, -1, sizeof dp);
        return helper(0,0,k,A);
    }
};