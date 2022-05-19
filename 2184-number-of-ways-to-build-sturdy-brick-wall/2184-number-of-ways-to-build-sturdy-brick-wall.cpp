class Solution {
    vector<vector<int>> dp;
    vector<vector<int>> adj;
    int mod = 1e9 + 7;
    void buildComb(int end, int mask, int w, vector<int>& bricks, vector<int>& combs) {
        if(end == w) {
            combs.push_back(mask ^ (1<<w));
        } else {
            for(auto& b : bricks) {
                if(end + b > w) continue;
                int nmask = mask | (1<<(end + b));
                buildComb(end + b, nmask, w, bricks, combs);
            }
        }
    }
    int dfs(int h, int b, int& height) {
        if(h == height) return 1;
        if(dp[h][b] != -1) return dp[h][b];
        dp[h][b] = 0;
        for(auto& nb : adj[b]) {
            dp[h][b] = (dp[h][b] + dfs(h + 1, nb, height)) % mod;
        }
        return dp[h][b];
    }
public:
    int buildWall(int height, int width, vector<int>& bricks) {
        vector<int> combs;
        buildComb(0, 0, width, bricks, combs);
        dp = vector<vector<int>>(height, vector<int>(combs.size(), -1));
        adj = vector<vector<int>>(combs.size());
        if(combs.size() == 1) {
            if(combs[0] == 0) return 1;
            if(height == 1) return 1;
            return 0;
        }
        for(int i = 0; i < combs.size(); i++) {
            for(int j = i; j < combs.size(); j++) {
                if(combs[i] & combs[j]) continue;
                if(i != j)
                    adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        
        int res = 0;
        height -= 1;
        for(int i = 0; i < combs.size(); i++) {
            res = (res + dfs(0, i, height)) % mod;
        }
        
        return res;
    }
};