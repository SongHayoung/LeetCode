class Solution {
public:
    bool sumGame(string s) {
        int q = 0, sum = 0, n = s.length();
        for(int i = 0; i < n / 2; i++) {
            if(s[i] == '?') q++;
            else sum += s[i] - '0';
        }
        for(int i = n / 2; i < n; i++) {
            if(s[i] == '?') q--;
            else sum -= s[i] - '0';
        }
        
        return q & 1 or sum + q / 2 * 9 != 0;
    }
};