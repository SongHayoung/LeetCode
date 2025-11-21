class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        long long len = s.length();
        vector<long long> p9(len + 1, 1);
        for (int i = 1; i <= len; ++i) p9[i] = p9[i - 1] * 9;

        long long res = 0;
        for (int len = 1; len < p9.size() - 1; ++len) res += p9[len];

        for(int i = 0; i < p9.size() - 1; i++) {
            int x = s[i] - '0';
            if(x == 0) return res;
            res += (x - 1) * p9[p9.size() - 2 - i];
        }
        return res + 1;
    }
};