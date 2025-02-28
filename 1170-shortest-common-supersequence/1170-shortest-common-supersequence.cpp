class Solution {
    string LCS(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) {
            if(i < n and j < m and a[i] == b[j]) {
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
            }
            if(i < n) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }
            if(j < m) {
                dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            }
        }
        int i = n, j = m;
        string res = "";
        while(i and j) {
            if(dp[i-1][j-1] == dp[i][j] - 1 and a[i-1] == b[j-1]) {
                i -= 1, j -= 1;
                res.push_back(a[i]);
            } else if(dp[i-1][j] == dp[i][j]) i--;
            else j--;
            
        }
        reverse(begin(res), end(res));
        return res;
    }
public:
    string shortestCommonSupersequence(string a, string b) {
        string lcs = LCS(a,b);
        string res = "";
        while(a.size() and b.size() and lcs.size()) {
            while(a.size() and a.back() != lcs.back()) {
                res.push_back(a.back()); a.pop_back();
            }
            while(b.size() and b.back() != lcs.back()) {
                res.push_back(b.back()); b.pop_back();
            }
            res.push_back(lcs.back()); lcs.pop_back(); a.pop_back(); b.pop_back();
        }
        while(a.size()) {
            res.push_back(a.back()); a.pop_back();
        }
        while(b.size()) {
            res.push_back(b.back()); b.pop_back();
        }
        reverse(begin(res), end(res));
        return res;
    }
};