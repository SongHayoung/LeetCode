int dp[2][2][2][51][21][3][256];
class Solution {

    int helper(string& s, int p, int l, int u, int d, int choice, char prev, int conseqtive) {
        if(choice > 20) {return 987654321;}
        if(dp[l][u][d][p][choice][conseqtive][prev] != -1) return dp[l][u][d][p][choice][conseqtive][prev];
        int& res = dp[l][u][d][p][choice][conseqtive][prev] = 987654321;
        if(s.length() == p) {return res = max(max(0, 6 - choice),(3 - l - u - d));}

        int nConsequtive = prev == s[p] ? conseqtive + 1 : 1;

        if(nConsequtive != 3) {
            bool nl = l | islower(s[p]);
            bool nu = u | isupper(s[p]);
            bool nd = d | isdigit(s[p]);

            res = min(res, helper(s, p + 1, nl, nu, nd, choice + 1, s[p], nConsequtive));
        }

        //delete
        res = min(res, helper(s, p + 1, l, u, d, choice, prev, conseqtive) + 1);

        //modify
        res = min(res, helper(s, p + 1, l, u, 1, choice + 1, '#', 1) + 1);
        res = min(res, helper(s, p + 1, 1, u, d, choice + 1, '#', 1) + 1);
        res = min(res, helper(s, p + 1, l, 1, d, choice + 1, '#', 1) + 1);


        if(nConsequtive == 3) {
            res = min(res, helper(s, p, 1, u, d, choice + 1, '#', 1) + 1);
            res = min(res, helper(s, p, l, 1, d, choice + 1, '#', 1) + 1);
            res = min(res, helper(s, p, l, u, 1, choice + 1, '#', 1) + 1);
        }
        
        return res;
    }
public:
    int strongPasswordChecker(string password) {
        memset(dp,-1,sizeof(dp));
        return helper(password, 0, 0, 0, 0, 0, '#', 1);
    }
};