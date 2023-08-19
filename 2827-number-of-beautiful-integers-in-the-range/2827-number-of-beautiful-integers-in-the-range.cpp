class Solution {
    long long dp[10][22][20];
    long long calc(string& s, int p, int rem, int cnt, bool lo, bool zero, int k) {
        if(p == s.length()) return cnt == 10 and rem == 0;
        if(lo) {
            if(zero and dp[p][rem][cnt] != -1) return dp[p][rem][cnt];
            long long res = 0;
            for(int i = 0; i <= 9; i++) {
                int ncnt = cnt + (i & 1 ? -1 : +1);
                if(!zero and i == 0) ncnt = cnt;
                res += calc(s,p+1,(rem * 10 + i) % k, ncnt, true, zero | i, k);
            }
            if(zero) dp[p][rem][cnt] = res;
            return res;
        }
        long long res = 0;
        for(int i = 0; i < s[p] - '0'; i++) {
            int ncnt = cnt + (i & 1 ? -1 : +1);
            if(!zero and i == 0) ncnt = cnt;
            res += calc(s,p+1,(rem * 10 + i) % k, ncnt, true, zero | i, k);
        }
        res += calc(s,p+1,(rem * 10 + s[p] - '0') % k, cnt + ((s[p]-'0') & 1 ? -1 : +1), false, true, k);
        return res;
    }
    long long helper(long long n, long long k) {
        if(n == 0) return 1;
        
        memset(dp,-1,sizeof dp);
        string s = to_string(n);
        return calc(s,0,0,10,false,false,k);
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return helper(high,k) - helper(low-1,k);
    }
};