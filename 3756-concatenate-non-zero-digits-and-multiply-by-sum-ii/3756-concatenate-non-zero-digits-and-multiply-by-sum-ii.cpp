class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(), mod = 1e9 + 7;
        vector<int> at(n);
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '0') k++;
            at[i] = k;
        }
        vector<long long> sum(k + 1, 0), hash(k + 1, 0), pow10(k + 1, 1);
        int idx = 0;
        for (int i = 0; i < n; ++i) if (s[i] != '0') {
                int d = s[i] - '0';
                ++idx;
                sum[idx] = sum[idx - 1] + d;
                hash[idx] = (hash[idx - 1] * 10 + d) % mod;
                pow10[idx] = (pow10[idx - 1] * 10) % mod;
            }
        vector<int> res;
        for (auto &q : queries) {
            int l = q[0] > 0 ? at[q[0] - 1] : 0, r = at[q[1]], len = r - l;
            if(len == 0) res.push_back(0);
            else {
                long long a = (sum[r] - sum[l]) % mod;
                long long b = (hash[r] - (hash[l] * pow10[len]) % mod + mod) % mod;
                res.push_back(a * b % mod);
            }
        }
        return res;
    }
};