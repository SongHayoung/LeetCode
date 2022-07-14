class Solution {
    long long dp[101010];
    unordered_map<int, vector<pair<int, int>>> mp;
    int fin = 0;
    long long helper(int now) {
        if(now > fin) return 0;
        if(dp[now] != -1) return dp[now];
        long long& res = dp[now] = helper(now + 1);
        for(auto [end, tip] : mp[now]) {
            res = max(res, end - now + tip + helper(end));
        }
        return res;
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& A) {
        memset(dp, -1, sizeof dp);
        for(auto& a : A) {
            int s = a[0], e = a[1], t = a[2];
            mp[s].push_back({e,t});
            fin = max(fin, s);
        }
        return helper(0);
    }
};