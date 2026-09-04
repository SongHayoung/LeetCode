class Solution {
public:
    int minFlips(string s) {
        int res = INT_MAX, one = count(begin(s), end(s), '1'), n = s.length();
        if(n <= 2) return 0;
        res = min(one, n - one);
        if(one) res = min(res, one - 1);
        if(s[0] == '1') one--;
        if(s[n-1] == '1') one--;
        res = min(res, one);
        return res;
    }
};