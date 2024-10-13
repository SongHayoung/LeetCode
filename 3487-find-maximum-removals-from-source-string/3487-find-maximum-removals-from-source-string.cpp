class Solution {
public:
    int maximumRemovals(string source, string pattern, vector<int>& order) {
        int n = source.size(), m = pattern.size();
        vector<int> dp(m + 1, INT_MIN);
        dp[0] = 0;
        for(int i = 0, k = 0; i < n; i++) {
            bool fl = k < order.size() and order[k] == i;
            for(int j = m; j >= 0; j--) {
                if(j + 1 <= m and pattern[j] == source[i]) {
                    dp[j+1] = max(dp[j+1], dp[j]);
                }
                dp[j] += fl;
            }
            if(fl) k++;
        }
        return dp[m];
    }
};