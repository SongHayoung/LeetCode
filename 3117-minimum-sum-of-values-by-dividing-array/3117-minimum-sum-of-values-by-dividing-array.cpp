class Solution {
public:
    int minimumValueSum(vector<int>& A, vector<int>& bits) {
        unordered_map<int, int> dp[bits.size() + 1];
        dp[0][INT_MAX] = 0;
        for(auto& x : A) {
            dp[bits.size()] = {};
            for(int i = bits.size() - 1; i >= 0; i--) {
                unordered_map<int,int> now;
                for(auto& [k,v] : dp[i]) {
                    int bit = k & x;
                    if(bit == bits[i]) {
                        if(!dp[i+1].count(INT_MAX)) dp[i+1][INT_MAX] = INT_MAX;
                        dp[i+1][INT_MAX] = min(dp[i+1][INT_MAX], v + x);
                    }
                    if(!now.count(bit)) now[bit] = INT_MAX;
                    now[bit] = min(now[bit], v);
                }
                swap(now, dp[i]);
            }
        }
        if(dp[bits.size()].count(INT_MAX)) return dp[bits.size()][INT_MAX];
        return -1;
    }
};