class Solution {
public:
    string getSmallestString(string s, int k) {
        for(int i = 0; i < s.length() and k; i++) {
            for(char ch = 'a'; ch <= 'z'; ch++) {
                int now = abs(s[i] - ch);
                int mi = min(now, 26 - now);
                if(mi <= k) {
                    k -= mi;
                    s[i] = ch;
                    break;
                }
            }
        }
        return s;
    }
};