class Solution {
    string helper(int n, int mod) {
        string res = "";
        while(n) {
            int m = n % mod;
            n /= mod;
            res.push_back(m < 10 ? m + '0' : m - 10 + 'A');
        }
        reverse(begin(res), end(res));
        return res;
    }
public:
    string concatHex36(int n) {
        return helper(n * n, 16) + helper(n * n * n, 36);
    }
};