class Solution {
public:
    int countHomogenous(string s) {
        if(s.length() == 0)
            return 0;

        long res = 0;
        long mod = 1e9 + 7, cnt = 1;
        for(int i = 0; i < s.length() - 1; i++, cnt++) {
            if(s[i] != s[i+1]) {
                res += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
        }
        res += cnt * (cnt + 1) / 2;
        return res % mod;
    }
};
