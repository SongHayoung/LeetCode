vector<int> manacher(string& s) {
    vector<int> dp(s.length());
    for(int i = 0, l = 0, r = -1; i < s.length(); i++) {
        dp[i] = max(0, min(r - i, r + l - i >= 0 ? dp[r + l - i] : -1));
        while(i + dp[i] < s.length() and i - dp[i] >= 0 and s[i-dp[i]] == s[i+dp[i]]) dp[i]++;
        if(r < i + dp[i]) {
            r = i + dp[i];
            l = i - dp[i];
        }
    }
    return dp;
}
vector<int> helper(string& s) {
    string ss = "#";
    for(auto& ch : s) {
        ss.push_back(ch);
        ss.push_back('#');
    }
    vector<int> mana = manacher(ss);
    vector<int> res(s.length());
    for(int i = 1; i < mana.size() - 1; i++) {
        int le = i - mana[i] + 1, ri = i + mana[i] - 1;
        int len = (ri - le + 1) / 2;
        res[le/2] = max(res[le/2], len);
    }
    return res;
}
struct RollingHash {
    vector<long long> hash, po;
    long long base, mod;
    RollingHash(string& s) : base(131), mod(1e9 + 7) {
        hash = vector<long long>(s.length() + 1), po = vector<long long>(s.length() + 1);
        po[0] = 1;
        for(int i = 0; i < s.length(); i++) {
            po[i+1] = po[i] * base % mod;
            hash[i+1] = (hash[i] * base + s[i] - 'a') % mod;
        }
    }
    long long get(int pos, int len) {
        return (hash[pos + len] - hash[pos] * po[len] % mod + mod) % mod;
    }
};
class Solution {
public:
    int longestPalindrome(string s, string t) {
        reverse(begin(t), end(t));
        auto sma = helper(s), tma = helper(t);
        sma.push_back(0); tma.push_back(0);
        RollingHash srh(s), trh(t);
        int res = max(*max_element(begin(sma), end(sma)), *max_element(begin(tma), end(tma)));
        auto search = [&](int len, long long hash, int pal) {
            int best = -1;
            for(int i = 0; i < (int)t.length() - len + 1; i++) {
                if(trh.get(i,len) == hash) {
                    best = max(best, tma[i+len]);
                }
            }
            if(best != -1) best = max(best, pal);
            return pair<bool,int>{best != -1, best};
        };
        for(int i = 0; i < s.length(); i++) {
            int l = 1, r = s.length() - i;
            while(l <= r) {
                int m = l + (r - l) / 2;
                auto [ok, best] = search(m,srh.get(i,m), sma[i+m]);
                if(ok) {
                    l = m + 1;
                    res = max(res, m * 2 + best);
                } else r = m - 1;
            }
        }
        
        return res;
    }
};