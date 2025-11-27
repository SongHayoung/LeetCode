class Solution {
    long long mod = INT_MAX;
public:
    long long numDistinct(string s, string t) {
        int m = t.length();
        vector<long long> dp(m);
        for(auto& ch : s) {
            for(int j = m - 1; j >= 0; j--) {
                if(ch != t[j]) continue;
                if(j == 0) dp[0]++;
                else dp[j] = (dp[j] + dp[j-1]) % INT_MAX;
            }
        }
        return dp[m-1];
    }
};