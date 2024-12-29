class Solution {
public:
    int numWays(vector<string>& A, string& s) {
        int m = A.size(), n = s.length(), k = A[0].size();
        vector<vector<long long>> cnt(k,vector<long long>(26));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < k; j++) {
                cnt[j][A[i][j]-'a']++;
            }
        }
        vector<long long> dp(k);
        long long mod = 1e9 + 7, res = 0;
        for(int i = k - 1, x = s[n-1] - 'a'; i >= 0; i--) {
            dp[i] = cnt[i][x];
        }
        for(int i = n - 2; i >= 0; i--) {
            int t = s[i] - 'a';
            vector<long long> dpp(k);
            long long suf = 0;
            for(int j = k - 1; j >= 0; j--) {
                dpp[j] = suf * cnt[j][t] % mod;
                suf = (suf + dp[j]) % mod;
            }
            
            swap(dp,dpp);
        }
        for(int i = 0; i < dp.size(); i++) res = (res + dp[i]) % mod;
        return res;
    }
};