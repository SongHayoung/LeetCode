class Solution {
    int helper(string& s, string p) {
        int res = 0;
        for(int i = s.length() - 1, j = 1; i >= 0; i--) {
            if(s[i] == p[j]) j -= 1;
            else res += 1;
            if(j == -1) return res;
            if(i == 0 and p == "00" and j == 0) return s.length() - 1;
        }
        return s.length();
    }
public:
    int minimumOperations(string num) {
        int res = num.length();
        res = min(res, helper(num,"00"));
        res = min(res, helper(num,"25"));
        res = min(res, helper(num,"50"));
        res = min(res, helper(num,"75"));
        return res;
    }
};