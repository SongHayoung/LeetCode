class Solution {
public:
    int countSubstrings(string s) {
        string ss = "#";
        for(auto& ch : s) {
            ss.push_back(ch);
            ss.push_back('#');
        }
        int n = ss.length(), res = 0;
        vector<int> dp(n);
        int l = 0, r = -1;
        for(int i = 0; i < n; i++) {
            dp[i] = max(0, min(r - i, (r + l - i >= 0 ? dp[r + l - i] : -1)));
            while(i + dp[i] < n and i - dp[i] >= 0 and ss[i-dp[i]] == ss[i+dp[i]])
                dp[i]++;
            res += dp[i] / 2;
            if(i + dp[i] > r) {
                r = i + dp[i];
                l = i - dp[i];
            }
        }
        return res;
    }
};