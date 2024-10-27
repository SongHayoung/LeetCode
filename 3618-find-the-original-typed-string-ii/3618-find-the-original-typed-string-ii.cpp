class Solution {
public:
    int possibleStringCount(string word, int k) {
        long long mod = 1e9 + 7, res = 0;
        word.push_back('#');
        vector<long long> buc;
        for(int i = 1, cnt = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) cnt++;
            else {
                buc.push_back(cnt);
                cnt = 1;
            }
        }
        vector<long long> suf(buc.size(), buc.back());
        for(int i = buc.size() - 2; i >= 0; i--) {
            suf[i] = suf[i+1] * buc[i] % mod;
        }
        if(buc.size() >= k) return suf[0];
        vector<long long> dp(k+1);
        dp[0] = 1;
        for(int i = 0; i < buc.size(); i++) {
            res = (res + dp[k] * suf[i] % mod) % mod;
            vector<long long> dpp(k+1);
            for(int j = 0; j < k; j++) {
                dpp[j+1] = (dpp[j+1] + dp[j]) % mod;
                long long until = j + buc[i];
                if(until <= k) {
                    if(until < k) dpp[until+1] = (dpp[until+1] - dp[j] + mod) % mod;
                } else {
                    long long cnt = until - k;
                    dpp[k] = (dpp[k] + cnt * dp[j] % mod) % mod;
                }
            }
            for(int j = 1; j < dpp.size(); j++) dpp[j] = (dpp[j] + dpp[j-1]) % mod;
            swap(dp,dpp);
        }
        return (res + dp[k]) % mod;
    }
};