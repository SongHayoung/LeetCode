long long dp[16][12][12];
class Solution {
    bool ok(int a, int b, int c) {
        if(a > b and b < c) return true;
        if(a < b and b > c) return true;
        return false;
    }
    long long po(int x) {
        long long res = 1;
        for(int i = 1; i < x; i++) res = res * 10;
        return res;
    }
    long long po2(string& s, int p) {
        if(p == s.length()) return 1;
        return stoll(s.substr(p)) + 1;
    }
    long long helper(string& s, int pos, long long prv, long long cur, bool less) {
        if(pos == s.length() - 1) return 0;
        if(less) {
            if(dp[pos][prv][cur] != -1) return dp[pos][prv][cur];
            long long& res = dp[pos][prv][cur] = 0;
            for(int i = 0; i < 10; i++) {
                res += helper(s,pos+1,cur,i,true) + ok(prv,cur,i) * po(s.length() - pos - 1);
            }
            return res;
        }
        long long res = 0, val = s[pos+1] - '0';
        for(int i = 0; i <= val; i++) {
            res += helper(s,pos+1,cur,i,i < val) + ok(prv,cur,i) * (i < val ? po(s.length() - pos - 1) : po2(s,pos + 2));
        }
        return res;
    }
    long long helper(long long x) {
        if(x < 100) return 0;
        memset(dp,-1,sizeof dp);
        string s = to_string(x);
        long long len = s.length(), res = 0;
        for(int start = len - 2; start; start--) {
            for(int i = 1; i < 10; i++) for(int j = 0; j < 10; j++) res += helper(s,start + 1,i,j,true);
        }
        for(int i = 1; i < s[0] - '0'; i++) {
            for(int j = 0; j < 10; j++) res += helper(s,1,i,j,true);
        }
        for(int j = 0; j < s[1] - '0'; j++) res += helper(s,1,s[0]-'0',j,true);
        res += helper(s,1,s[0]-'0',s[1]-'0',false);
        return res;
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        return helper(num2) - helper(num1 - 1);
    }
};