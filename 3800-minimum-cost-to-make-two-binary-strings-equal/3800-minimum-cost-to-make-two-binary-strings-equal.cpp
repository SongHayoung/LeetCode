class Solution {
public:
    long long minimumCost(string S, string T, int flipCost, int swapCost, int crossCost) {
        vector<long long> cnt{0,0};
        for(int i = 0; i < S.length(); i++) if(S[i] != T[i])  cnt[S[i]-'0']++;
        long long f = flipCost, s = swapCost, c = crossCost, p = min(s, 2 * f), diff = abs(cnt[0] - cnt[1]);
        if(cnt[0] < cnt[1]) swap(cnt[0], cnt[1]);

        long long res = diff * f + cnt[1] * p;
        if(diff / 2 > 0 and c - 2 * f + p < 0) res += diff / 2 * (c - 2 * f + p);
        return res;
    }
};