class Solution {
    int dp[101][101];
    int solution(string& s, int l, int r) {
        if(l == r) return 1;
        if(l + 1 == r) return s[l] == s[r] ? 1 : 2;
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = r - l + 1;
        for(int i = l; i < r; i++) {
            dp[l][r] = min(dp[l][r], solution(s,l,i) + solution(s,i+1,r) + (s[i] == s[r] ? -1 : 0));
        }
        return dp[l][r];
    }
public:
    int strangePrinter(string s) {
        s.erase(unique(s.begin(), s.end()), s.end());
        memset(dp, -1, sizeof(dp));
        return solution(s, 0, s.length()-1);
    }
};