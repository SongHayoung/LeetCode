class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<int> dp(n), meet(26, -1);
        for(int i = 0; i < n; i++) {
            if(i) dp[i] = dp[i-1];
            if(i >= 3) meet[word[i-3]-'a'] = i - 3;
            if(meet[word[i]-'a'] != -1) {
                dp[i] = max(dp[i], 1 + (meet[word[i]-'a'] ? dp[meet[word[i]-'a'] - 1] : 0));
            }
        }
        return dp.back();
    }
};