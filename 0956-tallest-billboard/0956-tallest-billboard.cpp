class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp{{0,0}};
        
        for(auto& n : rods) {
            for(auto& [k, v] : unordered_map<int,int>(dp)) {
                dp[k + n] = max(dp[k + n], v);
                dp[abs(k - n)] = max(dp[abs(k - n)], v + min(k, n));
            }
        }
        
        return dp[0];
    }
};
