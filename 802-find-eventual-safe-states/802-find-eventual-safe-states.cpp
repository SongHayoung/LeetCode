class Solution {
    int dp[10000];
    int helper(vector<vector<int>>& g, int n) {
        if(dp[n] != -1) return dp[n];
        if(g[n].empty()) return dp[n] = 1;
        dp[n] = 0;
        int mask = 1;
        for(auto near : g[n])
            mask &= helper(g,near);
        return dp[n] = mask;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        memset(dp,-1,sizeof(dp));
        int n = graph.size();
        vector<int> res;
        for(int i = 0; i < n; i++)
            if(helper(graph,i))
                res.push_back(i);
        return res;
    }
};