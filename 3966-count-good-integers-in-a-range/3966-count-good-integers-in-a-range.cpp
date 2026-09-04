long long dp[10][16];
class Solution {
    long long helper(string& s, int pos, int leading, int low, int prv, int k) {
        if(pos == s.length()) return k >= 0;
        if(leading) {
            long long res = 0;
            for(int i = 0; i < (low ? 10 : s[0] - '0'); i++) {
                res += helper(s,pos + 1, !i, 1, i, k);
            }
            if(!pos) {
                res += helper(s,pos + 1, false, 0, s[0] - '0', k);
            }
            return res;
        }
        if(low) {
            long long& res = dp[prv][pos];
            if(res != -1) return res;
            res = 0;
            for(int i = 0; i < 10; i++) {
                if(abs(prv - i) > k) continue;
                res += helper(s,pos + 1, false, true, i, k);
            }
            return res;
        }
        long long res = 0;
        for(int i = 0; i < s[pos] - '0' + 1; i++) {
            if(abs(prv - i) > k) continue;
            res += helper(s,pos + 1, false, i < (s[pos] - '0'), i, k);
        }
        return res;
    }
    long long helper(long long n, long long k) {
        memset(dp,-1,sizeof dp);
        string s = to_string(n);
        return helper(s,0,1,0,0,k);
    }
public:
    long long goodIntegers(long long l, long long r, int k) {
        return helper(r,k) - helper(l-1,k);
    }
};