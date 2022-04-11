class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> palindrome(n,vector<bool>(n, false));
        vector<int> dp(n);
        
        for(int i = 0; i < n; i++) {
            int mi = i;
            for(int j = 0; j <= i; j++) {
                if(s[j] == s[i] and (j + 1 > i - 1 or palindrome[j+1][i-1])) {
                    palindrome[j][i] = true;
                    mi = min(mi, (j == 0 ? 0 : dp[j-1] + 1));
                }
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            dp[i] = mi;
        }
        
        return dp.back();
    }
};