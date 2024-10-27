class Solution {
    long long mod = 1e9 + 7;
    unordered_map<string, int> dp;
    int helper(string s, int t) {
        if(dp.count(s)) return dp[s];
        vector<long long> cnt(26);
        for(auto& ch : s) cnt[ch-'a']++;
        for(int i = 0, z = 25; i < t; i++, z = (z + 25) % 26) {
            cnt[(z + 1) % 26] = (cnt[(z + 1) % 26] + cnt[z]) % mod;
        }
        long long res = 0;
        for(int i = 0; i < 26; i++) res = (res + cnt[i]) % mod;
        return dp[s] = res;
    }
public:
    int lengthAfterTransformations(string s, int t) {
        long long res = 0;
        for(auto& ch : s) res = (res + helper(string(1,ch), t)) % mod;
        return res;
    }
};