
vector<int> SA(vector<int>& s) {
    int n = s.size(), t = 1;
    vector<int> sa(n), tg(n + 1), g(n + 1);
    for(int i = 0; i < n; i++) sa[i] = i, g[i] = s[i];
    while(t <= n) {
        g[n] = -1;
        auto cmp = [&](int x, int y) {
            if(g[x] == g[y]) return g[x + t] < g[y + t];
            return g[x] < g[y];
        };

        sort(begin(sa), end(sa), cmp);

        tg[sa[0]] = 0;
        for(int i = 1; i < n; i++) tg[sa[i]] = tg[sa[i-1]] + cmp(sa[i-1], sa[i]);

        swap(g,tg);
        t <<= 1;
    }
    return sa;
}

vector<int> LCP(vector<int>& sa, vector<int>& s) {
    int n = s.size(), len = 0;
    vector<int> rsa(n), lcp(n);
    for(int i = 0; i < n; i++) rsa[sa[i]] = i;
    for(int i = 0; i < n; i++) {
        int k = rsa[i];
        if(k) {
            int j = sa[k-1];
            while(i + len < n and j + len < n and s[i + len] == s[j + len]) ++len;
            lcp[k] = len;
            if(len) --len;
        }
    }
    vector<int> res(n);
    for(int i = 0; i < n; i++) res[i] = lcp[sa[i]];
    return lcp;
}

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        auto sa = SA(nums);
        auto lcp = LCP(sa,nums);
        int res = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i == n - 1 or lcp[i+1] <= lcp[i]) {
                res = min(res, lcp[i] + 1);
            }
        }
        return res;
    }
};