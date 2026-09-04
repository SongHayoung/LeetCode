class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        vector<int> pre(n + 1);
        for(int i = 0; i < n; i++) pre[i+1] = pre[i] + (s[i] == '1');
        auto one = [&](int l, int r) {
            if(l > r) return 0;
            return pre[r + 1] - pre[l];
        };
        auto zero = [&](int l, int r) {
            if(l > r) return 0;
            return r - l + 1 - one(l,r);
        };
        unordered_map<int,vector<int>> dp;
        dp[0].push_back(-1);
        int now = 0, res = 0;
        for(int i = 0; i < n; i++) {
            now += (s[i] == '1') ? 1 : -1;
            dp[now].push_back(i);
            res = max(res, i - dp[now][0]);
            for(auto& pos : dp[now + 2]) {
                int len = i - pos;
                if(len <= res) break;
                if(one(0,pos - 1) or one(i + 1, n - 1)) res = len;
            }
            for(auto& pos : dp[now - 2]) {
                int len = i - pos;
                if(len <= res) break;
                if(zero(0,pos - 1) or zero(i + 1, n - 1)) res = len;
            }
        }
        return res;
    }
};
