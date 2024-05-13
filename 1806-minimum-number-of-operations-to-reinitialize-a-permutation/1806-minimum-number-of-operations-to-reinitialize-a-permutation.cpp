class Solution {
    int lcm(int a, int b) {
        int g = __gcd(a,b);
        return a / g * b;
    }
    int uf[1010];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu,pv);
    }
public:
    int reinitializePermutation(int n) {
        for(int i = 0; i < n; i++) uf[i] = i;
        for(int i = 0; i < n; i++) uni(i, (i & 1 ? (n / 2 + (i - 1) / 2) : i / 2));
        unordered_map<int,int> freq;
        for(int i = 0; i < n; i++) freq[find(i)]++;
        int res = 1;
        for(auto& [_,v] : freq) res = lcm(res,v);
        return res;
    }
};