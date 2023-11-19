
class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0, w = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') res += w;
            else w += 1;
        }
        return res;
    }
};
