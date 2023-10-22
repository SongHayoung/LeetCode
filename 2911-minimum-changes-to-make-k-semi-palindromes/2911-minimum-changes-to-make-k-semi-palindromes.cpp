
class Solution {
    long long dp[222][222];
    long long cost[222][222];
    long long helper(string& s, int p, int dep) {
        if(dp[p][dep] != -1) return dp[p][dep];
        if(p == s.length()) return dep == 0 ? 0 : INT_MAX;
        if(dep == 0) return INT_MAX;
        long long& res = dp[p][dep] = INT_MAX;
        for(int i = p + 1; i < s.length(); i++) {
            res = min(res, cost[p][i] + helper(s,i+1,dep-1));
        }
        return res;
    }
public:
    int check(string& s, int l, int r) {
        if(l == r) return INT_MAX;
        int len = r - l + 1, res = INT_MAX;
        unordered_set<int> div{1};
        for(int d = 2; d * d <= len; d++) {
            if(len % d) continue;
            div.insert(d);
            div.insert(len / d);
        }
        unordered_map<int, int> cand;
        for(int p = l; p <= r; p++) {
            int th = p - l;
            for(auto& x : div) {
                int buc = th % x, seq = th / x;
                int tot = len / x;
                int oth = tot - seq - 1;
                int pos = oth * x + buc + l;
                if(p < pos) {
                    if(s[p] != s[pos]) cand[x] += 1;
                    else cand[x] += 0;
                    
                }
            }
        }
        for(auto& [_,v] : cand) res = min(res,v);
        return res;
    }
    int minimumChanges(string s, int k) {
        memset(dp,-1,sizeof dp);
        for(int i = 0; i < s.length(); i++) {
            for(int j = i; j < s.length(); j++) {
                cost[i][j] = check(s,i,j);
            }
        }
        return helper(s,0,k);
    }
};