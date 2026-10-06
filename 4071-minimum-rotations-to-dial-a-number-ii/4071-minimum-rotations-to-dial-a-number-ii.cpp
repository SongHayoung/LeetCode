
class Solution {
public:
    long long minRotations(int n, string s) {
        auto cost = [&](char a, char b) {
            int ab = abs(a-b);
            return min(10-ab,ab);
        };
        s = "0" + s;
        vector<int> suf(s.length() + 1);
        for(int i = s.length() - 2; i >= 0; i--) {
            suf[i] = suf[i+1] + cost(s[i],s[i+1]);
        }
       int res = suf[1] + cost('0', s.back()), pre = 0;
        for(int i = 1; i <= n; i++) {
            pre += cost(s[i],s[i-1]);
            
            res = min(res, pre + suf[i+1] + cost(s[i],s.back()));
        }
        return res;
    }
};