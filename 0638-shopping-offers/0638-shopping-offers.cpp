class Solution {
    long long dp[11][11][11][11][11][11];
    long long helper(vector<int>& C, vector<vector<int>>& O, int a, int b, int c, int d, int e, int f) {
        if(dp[a][b][c][d][e][f] != -1) return dp[a][b][c][d][e][f];
        long long& res = dp[a][b][c][d][e][f] = a * C[0] + b * C[1] + c * C[2] + d * C[3] + e * C[4] + f * C[5];
        for(auto& x : O) {
            int na = a - x[0];
            int nb = b - x[1];
            int nc = c - x[2];
            int nd = d - x[3];
            int ne = e - x[4];
            int nf = f - x[5];
            if(na < 0 or nb < 0 or nc < 0 or nd < 0 or ne < 0 or nf < 0) continue;
            res = min(res, helper(C,O,na,nb,nc,nd,ne,nf) + x[6]);
        }
        return res;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        memset(dp,-1,sizeof dp);
        dp[0][0][0][0][0][0] = 0;
        while(price.size() < 6) price.push_back(0);
        while(needs.size() < 6) needs.push_back(0);
        for(auto& x : special) {
            while(x.size() < 7) {
                x.push_back(0);
                swap(x[x.size() - 1], x[x.size() - 2]);
            }
        }
        return helper(price,special,needs[0],needs[1],needs[2],needs[3],needs[4],needs[5]);
    }
};