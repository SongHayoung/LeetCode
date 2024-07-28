
class Solution {
public:
    int numberOfSubstrings(string s) {
        long long n = s.length();
        vector<int> pre{0};
        for(int i = 0; i < n; i++) pre.push_back(pre.back() + s[i] - '0');
        auto one = [&](int l, int r) {
            return pre[r + 1] - pre[l];
        };
        auto zero = [&](int l, int r) {
            return r - l + 1 - one(l,r);
        };
        auto calc = [&](int o, int z) {
            long long l = 0, r = o - z, res = 0;
            while(l <= r) {
                long long m = l + (r - l) / 2;
                bool ok = o >= (z + m) * (z + m);
                if(ok) {
                    res = m;
                    l = m + 1;
                } else r = m - 1;
            }
            return res;
        };
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            long long o = s[i] == '1', z = s[i] == '0', j = i;
            if(o) res++;
            while(j < n - 1) {
                if(o >= z * z) {
                    long long d = calc(o,z);
                    if(d == 0) {
                        j++;
                        if(j < n) {
                            if(s[j] == '1') o++;
                            else z++;
                            if(o - z * z >= 0) res++;
                        }
                    } else {
                        long long nj = min(n - 1, j + d);
                        res += nj - j;
                        o += one(j+1,nj);
                        z += zero(j+1,nj);
                        j = nj;
                    }
                } else {
                    long long d = z * z - o - 1;
                    if(d == 0) {
                        j++;
                        if(s[j] == '1') o++;
                        else z++;
                        if(o >= z * z)
                            res++;
                    } else {
                        long long nj = min(n-1, j + d);
                        o += one(j+1, nj);
                        z += zero(j + 1, nj);
                        j = nj;
                    }
                }
            }
        }
        return res;
    }
};