class Solution {
    unordered_map<int, vector<string>> mp;
    unordered_map<string, int> dp;
    bool reachable(string& from, string& to) {
        int diff = 0, i = 0, j = 0, n = from.length(), m = to.length();
        while(i < n and j < m) {
            if(from[i] == to[j]) {
                i++,j++;
            } else {
                j++;
                if(++diff >= 2) return false;
            }
        }
        return i == n and diff <= 1;
    }
    int helper(string& s) {
        if(dp.count(s)) return dp[s];
        dp[s] = 1;
        for(auto& nxt : mp[s.length() + 1]) {
            if(reachable(s, nxt))
                dp[s] = max(dp[s], 1 + helper(nxt));
        }
        return dp[s];
    }
public:
    int longestStrChain(vector<string>& words) {    
        int res = 0;
        for(auto& w : words)
            mp[w.length()].push_back(w);
        for(auto& w : words) {
            res = max(res, helper(w));
        }
        return res;
    }
};