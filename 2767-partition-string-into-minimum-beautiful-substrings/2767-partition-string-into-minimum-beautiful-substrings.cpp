class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        vector<long long> dp(s.length(), INT_MAX);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') continue;
            int val = 0, po = 1;
            for(int j = i; j < s.length(); j++) {
                val = val * 2 + s[j] - '0';
                while(po < val) po = po * 5;
                if(val == po) dp[j] = min(dp[j], 1 + (i ? dp[i-1] : 0ll));
            }
        }
        return dp.back() <= s.length() ? dp.back() : -1;
    }
};