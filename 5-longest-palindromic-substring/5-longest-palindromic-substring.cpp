class Solution {
    
public:
    string longestPalindrome(string s) {
        string target = "#";
        for(auto ch : s)
            target += string(1,ch) + "#";
        vector<int> dp(target.length(),0);
        int l = 0, r = -1;
        for(int i = 1; i < target.length() - 1; i++) {
            dp[i] = max(0, min(r - i, l + r - i >= 0 ? dp[l + r - i] : 0));
            while(i - dp[i] >= 0 and i + dp[i] < target.length() and target[i-dp[i]] == target[i+dp[i]]) {
                dp[i]++;
            }
            if(i + dp[i] > r) {
                r = i + dp[i];
                l = i - dp[i];
            }
        }
        int mid = -1, ma = -1;
        for(int i = 0; i < dp.size(); i++) {
            if(ma < dp[i]) {
                ma = dp[i];
                mid = i;
            }
        }
        
        string res = "";
        for(int i = max(0, mid - dp[mid] + 1); i <= min(mid + dp[mid] - 1, (int)target.length() - 1); i++) {
            if(target[i] != '#') {
                res += target[i];
            }
        }
        return res;
    }
};