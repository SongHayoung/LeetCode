class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length(), res = 0;
        for(int i = n - 1, count = 0; i >= 0; i--) {
            if(s[i] == '0') count++;
            if(s[i] == '1') {
                res = min(count, 1 + res);
            }
        }
        return res;
    }
};