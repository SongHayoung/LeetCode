class Solution {
    long long mod = 1e9 + 7, p = 31;
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        unordered_set<long long> us;
        vector<long long> pow(n+1,1);
        vector<long long> hash(n+1,text[0]);
        for(int i = 1; i <= n; i++) {
            pow[i] = pow[i-1] * p % mod;
            hash[i] = (hash[i-1] + pow[i] * text[i] % mod) % mod;
        }
        for(int len = 1; len <= n / 2; len++) {
            for(int i = 0; i <= n - len - len; i++) {
                long long now = (hash[i+len-1] - (i ? hash[i-1] : 0) + mod) % mod;
                long long next = (hash[i+len+len-1] - hash[i+len-1] + mod) % mod;
                now = now * pow[n-1-i] % mod;
                next = next * pow[n-1-i-len] % mod;
                if(now != next or us.count(now)) continue;
                us.insert(now);
            }
        }
        return us.size();
    }
};