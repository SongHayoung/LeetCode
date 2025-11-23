class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long T = 1ll * n * (n + 1) / 2;
        if(llabs(target) > T or ((T ^ target) & 1)) return {};
        long long U = (T - target) / 2;
        vector<char> neg(n + 1, 0);
        for (int i = n; i >= 1; --i) if (i <= U) { neg[i] = 1; U -= i; }
        vector<int> res;
        for (int i = n; i >= 1; --i) if (neg[i]) res.push_back(-i);
        for (int i = 1; i <= n; ++i) if (!neg[i]) res.push_back(i);
        return res;
    }
};