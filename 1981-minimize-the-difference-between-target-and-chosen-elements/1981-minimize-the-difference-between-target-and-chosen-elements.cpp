class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<5050> dp;
        dp[0] = 1;
        for(auto& m : mat) {
            bitset<5050> dpp;
            for(auto& x : m) dpp |= (dp<<x);
            swap(dp,dpp);
        }
        int res = INT_MAX;
        for(int i = 1; i < 5000; i++) if(dp[i]) res = min(res, abs(target - i));
        return res;
    }
};