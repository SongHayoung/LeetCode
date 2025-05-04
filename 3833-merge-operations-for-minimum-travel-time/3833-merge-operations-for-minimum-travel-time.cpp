long long dp[55][55][22], pre[55];
class Solution {
    long long helper(vector<int>& P, int prv, int pos, int op) {
        if(pos == P.size() - 1) return op ? INT_MAX : 0;
        if(dp[prv][pos][op] != -1) return dp[prv][pos][op];
        int c = pre[pos+1] - pre[prv];
        long long& res = dp[prv][pos][op] = helper(P,pos+1,pos+1,op) + c * (P[pos+1] - P[pos]);
        for(int np = pos + 1; np < P.size() and (np - pos - 1) <= op; np++) {
            res = min(res, (P[np] - P[pos]) * c + helper(P,pos+1,np,op - (np - pos - 1)));
        }
        return res;
    }
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++) pre[i+1] = pre[i] + time[i];
        return helper(position,0,0,k);
    }
};
