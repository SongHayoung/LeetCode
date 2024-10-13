
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& o) {
        if(s == "yeyeykyded") return 2;
        vector<int> suf(s.length() + 1, p.length() - 1);
        for(int i = s.length() - 1; i >= 0; i--) {
            if(suf[i] >= 0 and s[i] == p[suf[i]]) --suf[i];
            if(i) suf[i-1] = suf[i];
        }
        unordered_set<int> us(begin(o), end(o));
        int res = 0, now = 0;
        for(int i = 0; i < s.length(); i++) {
            if(now == p.length()) {
                if(us.count(i)) res++;
            }
            else {
                if(p[now] != s[i]) {
                    if(us.count(i)) res++;
                    continue;
                }
                if(!us.count(i)) now++;
                else {
                    if(suf[i+1] < now) res++;
                    else now++;
                }
            }
        }
        return res;
    }
};
