class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), res = INT_MAX, a = count(begin(s), end(s),'a'), pb = 0, pa = 0, b = n - a;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                a--;
                res = min(res, pb + a);
                pa++;
            } else {
                res = min(res, pb + a);
                pb++;
                b--;
            }
        }
        return res;
    }
};