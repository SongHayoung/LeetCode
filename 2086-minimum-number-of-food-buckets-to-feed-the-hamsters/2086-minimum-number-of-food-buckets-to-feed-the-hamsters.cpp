class Solution {
public:
    int minimumBuckets(string& s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'H') {
                int cnt = 0;
                if(i == 0 or s[i-1] == 'H') cnt++;
                if(i + 1 == s.length() or s[i+1] == 'H') cnt++;
                if(cnt == 2) return -1;
            }
        }
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'H') {
                res++;
                if(i + 1 < s.length() and s[i+1] == '.') {
                    if(i + 2 < s.length() and s[i+2] == 'H') {
                        s[i+2] = 'X';
                    }
                }
            }
        }
        return res;
    }
};