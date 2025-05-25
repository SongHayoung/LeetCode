class Solution {
    bool cons(char a, char b) {
        int d = abs(a-b);
        return d == 1 or d == 25;
    }
public:
    string lexicographicallySmallestString(string s) {
        int n = s.size();
        vector<vector<bool>> rem(n, vector<bool>(n));
        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len - 1 < n; ++l) {
                int r = l + len - 1;
                for (int k = l + 1; k <= r; ++k) {
                    if (cons(s[l],s[k]) and (k - l == 1 or rem[l+1][k-1]) and (k == r or rem[k+1][r])) {
                        rem[l][r] = true;
                        break;
                    }
                }
            }
        }
        vector<vector<string>> dp(n, vector<string>(n));
        for (int l = n - 1; l >= 0; --l) {
            dp[l][l] = rem[l][l] ? "" : string(1, s[l]);
            for (int r = l + 1; r < n; ++r) {
                if (rem[l][r]) {
                    dp[l][r].clear();
                    continue;
                }
                string best = s[l] + dp[l+1][r];
                for (int k = l + 1; k <= r; ++k) {
                    if (cons(s[l],s[k]) and (k - l == 1 or rem[l+1][k-1])) {
                        string cand = (k+1 <= r ? dp[k+1][r] : "");
                        best = min(best, cand);
                    }
                }
                dp[l][r] = move(best);
            }
        }
        return dp[0][n-1];
    }
};