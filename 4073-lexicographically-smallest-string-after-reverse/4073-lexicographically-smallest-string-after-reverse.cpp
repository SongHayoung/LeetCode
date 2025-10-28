class Solution {
public:
    string lexSmallest(string s) {
        int n = s.length();
        string res = s;
        for(int i = 2; i <= n; i++) {
            reverse(begin(s), begin(s) + i);
            res = min(res, s);
            reverse(begin(s), begin(s) + i);
            reverse(end(s) - i, end(s));
            res = min(res, s);
            reverse(end(s) - i, end(s));
        }
        return res;
    }
};