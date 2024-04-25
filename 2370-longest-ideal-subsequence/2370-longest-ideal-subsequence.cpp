class Solution {
    vector<vector<int>> mp;
    int dp[101010];
    int helper(string& s, int p, int k) {
        if(dp[p] != -1) return dp[p];
        int& res = dp[p] = 1;
        for(int ch = max((s[p] - k - 'a'),0); ch <= min((s[p] + k - 'a'),25); ch++) {
            if(mp[ch].empty()) continue;
            auto lb = lower_bound(begin(mp[ch]), end(mp[ch]), p + 1);
            if(lb == end(mp[ch])) continue;

            res = max(res, 1 + helper(s,*lb,k));
        }
        return res;
    }
public:
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof dp);
        mp = vector<vector<int>>(26);
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]-'a'].push_back(i);
        }
        int res = 0;
        for(int ch = 0; ch < 26; ch++) {
            if(mp[ch].empty()) continue;
            res = max(res, helper(s,mp[ch][0], k));
        }
        return res;
    }
};