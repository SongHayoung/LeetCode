unordered_map<int,int> dp[9][77];
class Solution {
    int helper(int x, int prod, int sum) {
        if(x == 0) return prod % sum == 0;
        if(dp[x][sum].count(prod)) return dp[x][sum][prod];
        int& res = dp[x][sum][prod] = 0;
        if(!prod) return res = pow(10,x);
        for(int i = 0; i < 10; i++) {
            res += helper(x-1, prod * i, sum + i);
        }
        return res;
    }
    int helper(string& s, int pos, bool less, int prod, int sum) {
        if(pos == s.size()) return sum and prod % sum == 0;
        if(less) {
            int res = 0;
            if(!sum) {
                res += helper(s,pos+1,true,0,0);
                for(int i = 1; i < 10; i++) {
                    res += helper(s.length() - pos - 1, i, i);
                }
            } else {
                res += helper(s.length() - pos, prod, sum);
            }
            return res;
        }
        int res = helper(s,pos+1,false,pos ? (s[pos]-'0') * prod : s[pos] - '0', sum + s[pos] - '0');
        for(int i = 0; i < s[pos] - '0'; i++) {
            res += helper(s,pos+1,true, pos ? i * prod : i, sum + i);
        }
        return res;
    }
    int helper(int n) {
        if(!n) return 0;
        for(int i = 0; i < 8; i++) for(int j = 0; j < 66; j++) dp[i][j] = {};
        string s = to_string(n);
        return helper(s,0,false,0,0);
    }
public:
    int beautifulNumbers(int l, int r) {
        return helper(r) - helper(l-1);
    }
};