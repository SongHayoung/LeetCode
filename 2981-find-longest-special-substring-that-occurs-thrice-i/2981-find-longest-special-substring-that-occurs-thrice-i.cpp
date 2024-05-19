class Solution {
public:
    int maximumLength(string s) {
        int n = s.length(), res = -1;
        vector<vector<int>> freq(26, vector<int>(n+1));
        for(int i = 1, cnt = 1; i <= n; i++) {
            if(i == n or s[i-1] != s[i]) {
                int x = s[i-1]-'a';
                for(int j = 1, now = cnt; j <= cnt; j++, now--) {
                    freq[x][j] += now;
                    if(freq[x][j] >= 3) res = max(res, j);
                }
                cnt = 1;
            } else cnt++;
        }
        return res;
    }
};