class Solution {
public:
    string shortestPalindrome(string s) {
        string extend = "#";
        for(auto& ch : s) {
            extend.push_back(ch);
            extend.push_back('#');
        }
        
        int l = 0, r = -1, n = extend.length();
        vector<int> dp(n);
        int res = 0;
        for(int i = 0; i < n; i++) {
            dp[i] = max(0, min(r - i, (r + l - i >= 0? dp[r + l - i] : -1)));
            while(i + dp[i] < n and i - dp[i] >= 0 and extend[i + dp[i]] == extend[i - dp[i]])
                dp[i]++;
            if(i - dp[i] < 0)
                res = max(res, i + dp[i]);
            if(i + dp[i] > r) {
                r = i + dp[i];
                l = i - dp[i];
            }
        }
        
        
        string rev = "";
        for(; res < n; res++) {
            if(extend[res] == '#') continue;
            rev.push_back(extend[res]);
        }
        reverse(begin(rev), end(rev));
        return rev + s;
    }
};