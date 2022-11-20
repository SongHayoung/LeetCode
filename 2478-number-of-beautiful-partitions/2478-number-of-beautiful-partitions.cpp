long long dp[1010][1010];
class Solution {
    bool prime(char ch) {
        return ch == '2' or ch == '3' or ch == '5' or ch == '7';
    }
    long long mod = 1e9 + 7;
    long long helper(string& s, int k, int& l, int p) {
        if(k == 0) return p == s.length();
        if(p + l * k > s.length() or !prime(s[p])) return 0;
        long long& res = dp[p][k];
        if(res != -1) return res;
        res = 0;
        for(int i = p + l - 1; i < s.length(); i++) {
            if(!prime(s[i])) res = (res + helper(s,k-1,l,i+1)) % mod;
        }

        return res;
    }
public:
    int beautifulPartitions(string s, int k, int minLength) {
        if(!prime(s.front()) or prime(s.back())) return 0;
        int n = s.length();
        memset(dp,-1, sizeof dp);
        return helper(s,k,minLength,0);
    }
};