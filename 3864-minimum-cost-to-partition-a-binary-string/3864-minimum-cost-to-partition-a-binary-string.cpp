int pre[101010];
class Solution {
    long long dnc(int l, int r, long long e, long long f) {
        long long len = r - l + 1;
        long long x = pre[r+1] - pre[l];
        long long res = x ? len * x * e : f;
        if(len % 2) return res;
        return min(res, dnc(l, l + len / 2 - 1, e, f) + dnc(l + len / 2, r, e, f));
    }
public:
    long long minCost(string s, int encCost, int flatCost) {
        for(int i = 0; i < s.length(); i++) pre[i+1] = pre[i] + (s[i] == '1');
        return dnc(0,s.length() - 1, encCost, flatCost);
    }
};