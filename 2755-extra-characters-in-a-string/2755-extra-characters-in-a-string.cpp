class Solution {
    int helper(string& s, int p, vector<int>& dp, unordered_set<string>& us) {
        if(p == s.length()) return 0;
        if(dp[p] != -1) return dp[p];
        int& res = dp[p] = 1 + helper(s,p+1,dp,us);
        string now = "";
        for(int i = p; i < s.length(); i++) {
            now.push_back(s[i]);
            if(us.count(now)) {
                res = min(res, helper(s,i+1,dp,us));
            }
        }
        return res;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> us(begin(dictionary), end(dictionary));
        vector<int> dp(s.length(), -1);
        int res = INT_MAX;
        for(int i = 0; i < s.length(); i++) {
            res = min(res, i + helper(s,i,dp,us));
        }
        return res;
    }
};
