class Solution {
    int dp[16][16];
    bool isPalindrome(string& str, int l, int r) {
        int ll = l, rr = r;
        if(dp[l][r] != -1) return dp[l][r];
        while(ll < rr) {  //use dp
            if(str[ll] != str[rr]) return dp[l][r] = false;
            ll++; rr--;
        }
        return dp[l][r] = true;
    }
    void backtracking(vector<vector<string>>& res, string& s, vector<string>& ans, int l) {
        if(l == s.length()) {
            res.push_back(ans);
            return;
        }
        for(int i = l; i < s.length(); i++) {
            if(isPalindrome(s,l,i)) {
                ans.push_back(s.substr(l,i-l+1));
                backtracking(res, s, ans, i + 1);
                ans.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        memset(dp, -1, sizeof(dp));
        vector<vector<string>> res;
        vector<string> ans;
        backtracking(res, s, ans, 0);
        return res;
    }
};