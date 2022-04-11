class Solution {
    int dp[1001][1001];
    int solution(string& s, int l, int r) {
        if(l == r) return 1;
        if(l + 1 == r and s[l] == s[r]) return 2;
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = max(solution(s, l + 1, r), solution(s, l, r-1));
        if(s[l] == s[r]) {
            dp[l][r] = max(dp[l][r], solution(s,l+1,r-1) + 2);
        }
        return dp[l][r];
    }
public:
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        
        return solution(s,0,s.length()-1);
    }
};