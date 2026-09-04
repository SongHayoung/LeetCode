class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.length();
        vector<vector<long long>> pre(n + 1, vector<long long>(3)), suf(n + 1, vector<long long>(3));
        for(int i = 0; i < s.length(); i++) {
            pre[i+1] = pre[i];
            if(s[i] == 'T') {
                pre[i+1][2] += pre[i+1][1];
            }
            if(s[i] == 'C') {
                pre[i+1][1] += pre[i+1][0];
            }
            if(s[i] == 'L') {
                pre[i+1][0]++;
            }
        }
        
        for(int i = s.length() - 1; i >= 0; i--) {
            suf[i] = suf[i+1];
            if(s[i] == 'T') {
                suf[i][2]++;
            }
            if(s[i] == 'C') {
                suf[i][1] += suf[i][2];
            }
            if(s[i] == 'L') {
                suf[i][0] += suf[i][1];
            }
        }

        long long res = 0;
        for(int i = 0; i <= n; i++) {
            long long l = 0, c = 0, t = 0;
            l += suf[i][1];
            c += pre[i][0] * suf[i][2];
            t += pre[i][1];
            res = max({res,l,c,t});
        }
        return res + pre.back()[2];
    }
};