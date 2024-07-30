class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), res = INT_MAX, a = count(begin(s), end(s),'a'), pb = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') a--;
            res = min(res, pb + a);
            if(s[i] == 'b') pb++;
        }
        return res;
    }
};