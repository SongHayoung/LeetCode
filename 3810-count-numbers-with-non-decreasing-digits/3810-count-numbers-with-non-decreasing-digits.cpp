long long dp[404][10], mod = 1e9 + 7;
class Solution {
    string base(string s, long long b, bool fl) {
        string res;
        vector<int> digits;
        for (char c : s) digits.push_back(c - '0');
        if(fl) {
            for(int i = digits.size() - 1, carry = 1; i >= 0 and carry; i--) {
                digits[i] -= 1;
                if(digits[i] < 0) {
                    digits[i] = 10 + digits[i];
                    carry = 1;
                } else carry = 0;
            }
        }
        while (digits.size()) {
            int carry = 0;
            vector<int> next;
            for (auto& digit : digits) {
                int cur = carry * 10 + digit;
                int q = cur / b;
                carry = cur % b;
                if (!next.empty() || q != 0)
                    next.push_back(q);
            }
            res.push_back(carry + '0');
            digits = next;
        }

        reverse(res.begin(), res.end());
        return res;
    }
    long long helper(string& s, int prv, int pos, bool lower, int base) {
        if(pos == s.length()) return 1;
        if(!lower) {
            long long res = 0;
            for(int i = prv; i <= s[pos]-'0'; i++) {
                res = (res + helper(s,i,pos+1,i != s[pos]-'0', base)) % mod;
            }
            return res;
        }
        if(dp[pos][prv] != -1) return dp[pos][prv];
        long long& res = dp[pos][prv] = 0;
        for(int i = prv; i < base; i++) {
            res = (res + helper(s,i,pos+1,lower,base)) % mod;
        }
        return res;
    }
    long long helper(string x, long long b, bool fl) {
        memset(dp,-1,sizeof dp);
        string s = base(x,b,fl);
        return helper(s,0,0,false,b);
    }
public:
    int countNumbers(string l, string r, int b) {
        return (helper(r,b,false) - helper(l,b,true) + mod) % mod;
    }
};
