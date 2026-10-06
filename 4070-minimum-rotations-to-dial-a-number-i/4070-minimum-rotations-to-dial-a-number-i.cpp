class Solution {
public:
    int minRotations(string s) {
        int n = s.length();
         s = "0" + s;
        int res = 0;
        for(int i = 1; i <= n; i++) {
            int ab = abs(s[i] - s[i-1]);
            res += min(10 - ab, ab);
        }
        return res;
    }
};