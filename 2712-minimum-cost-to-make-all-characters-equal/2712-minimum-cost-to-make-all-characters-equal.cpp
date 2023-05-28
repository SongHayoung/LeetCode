class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        vector<vector<long long>> le(n,vector<long long>(2)), ri(n,vector<long long>(2));
        for(long long i = 0, one = 0, zero = 0; i < n; i++) {
            if(s[i] == '0') {
                le[i][0] = one;
                zero = le[i][1] = one + (i+1);
            } else {
                one = le[i][0] = zero + (i+1);
                le[i][1] = zero;
            }
        }
        for(long long i = n - 1, one = 0, zero = 0; i >= 0; i--) {
            if(s[i] == '0') {
                ri[i][0] = one;
                zero = ri[i][1] = one + (n-i);
            } else {
                one = ri[i][0] = zero + (n-i);
                ri[i][1] = zero;
            }
        }
        long long res = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            res = min(res,le[i][0] + (i + 1 < n ? ri[i+1][0] : 0));
            res = min(res,le[i][1] + (i + 1 < n ? ri[i+1][1] : 0));
        }
        return res;
    }
};
