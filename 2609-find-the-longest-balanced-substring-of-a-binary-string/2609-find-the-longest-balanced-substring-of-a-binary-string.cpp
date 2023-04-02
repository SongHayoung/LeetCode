class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0, one = 0, zero = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                if(one) one = 0, zero = 1;
                else zero += 1;
            } else if(s[i] == '1') {
                one += 1;
                res = max(res, 2 * min(one,zero));
            }
        }
        return res;
    }
};