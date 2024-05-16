class Solution {
    int dp[1010];
    int helper(string& s, int p) {
        if(p == s.length()) return 0;
        if(dp[p] != -1) return dp[p];
        int& res = dp[p] = s.length();
        unordered_map<char,int> freq;
        int ma = 0;
        for(int i = p, len = 1; i < s.length(); i++, len++) {
            ma = max(ma, ++freq[s[i]]);
            if(len == freq.size() * ma) res = min(res, 1 + helper(s,i+1));
        }
        return res;
    }
public:
    int minimumSubstringsInPartition(string s) {
        memset(dp,-1,sizeof dp);
        return helper(s,0);
    }
};