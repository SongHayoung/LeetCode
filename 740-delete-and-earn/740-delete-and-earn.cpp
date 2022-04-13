class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int dp[10001] = {0,};
        for(auto& n : nums) dp[n] += n;
        int prev = 0, cur = 0;
        for(int i = 1; i < 10001; i++) {
            int sum = prev + dp[i];
            prev = cur;
            cur = max(cur, sum);
        }
        return max(prev,cur);
    }
};