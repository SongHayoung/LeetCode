class Solution {
    int dp[1001];
    vector<pair<int, int>> vec;
    int dfs(int& n, int p) {
        if(p == n) return 0;
        if(dp[p] != -1) return dp[p];
        
        int& res = dp[p] = vec[p].second;
        
        for(int i = p + 1; i < n; i++) {
            if(vec[i].first == vec[p].first) {
                continue;
            } else if(vec[i].second >= vec[p].second) {
                res = max(res, dfs(n,i) + vec[p].second);
            }
        }
        
        for(int i = p + 1; i < n and vec[p].first == vec[i].first; i++) {
            res = max(res, dfs(n,i) + vec[p].second);
        }
        
        return res;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < n; i++) {
            vec.push_back({ages[i], scores[i]});
        }

        sort(vec.begin(), vec.end());

        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, dfs(n,i));
        }

        return res;
    }
};