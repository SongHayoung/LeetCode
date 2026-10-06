class Solution {
public:
    int countRotations(string s, int k) {
        int res = 0, tot = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == s[(i+1)%n]) tot++;
        }
        for(int i = 0; i < n; i++) {
            int now = tot;
            if(s[i] == s[(i - 1 + n) % n]) now--;
            if(now == k) res++;
        }
        return res;
    }
};