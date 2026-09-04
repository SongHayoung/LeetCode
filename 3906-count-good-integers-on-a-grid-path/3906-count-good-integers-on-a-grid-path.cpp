
unordered_map<long long, long long> dp[16];
class Solution {
    long long helper(string& s, vector<int>& at, int pos, int lookup, int prv, bool less) {
        if(pos == s.length()) return 1;
        if(!less) {
            if(pos == at[lookup]) {
                long long res = 0;
                for(int i = prv; i < s[pos] - '0'; i++) {
                    res += helper(s,at,pos+1,lookup+1,i,true);
                }
                if(prv <= s[pos] - '0') {
                    res += helper(s,at,pos+1,lookup+1,s[pos]-'0',false);
                }
                return res;
            } else {
                long long res = 0;
                for(int i = 0; i < s[pos] - '0'; i++) {
                    res += helper(s,at,pos+1,lookup,prv,true);
                }
                res += helper(s,at,pos+1,lookup,prv,false);
                return res;
            }
        } else {
            if(dp[pos].count(prv)) return dp[pos][prv];
            long long& res = dp[pos][prv] = 0;
            if(pos == at[lookup]) {
                for(int i = prv; i <= 9; i++) {
                    res += helper(s,at,pos+1,lookup+1,i,less);
                }
            } else {
                res = 10 * helper(s,at,pos+1,lookup,prv,less);
            }
            return res;
        }
    }
    long long helper(long long n, string& d) {
        string s = to_string(n);
        while(s.length() < 16) s = "0" + s;

        for(int i = 0; i < 16; i++) dp[i].clear();
        vector<int> at{0};
        int y = 0, x = 0;
        for(auto& ch : d) {
            if(ch == 'D') y++;
            else x++;
            at.push_back(y * 4 + x);
        }


        return helper(s,at,0,0,0,false);
    }
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        return helper(r, directions) - helper(l-1,directions);
    }
};