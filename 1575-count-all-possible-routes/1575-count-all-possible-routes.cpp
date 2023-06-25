class Solution {
    int memo[101][201];
    int mod = 1e9 + 7;
    int dp(vector<int>& l, int &t, int c, int f) {
        if(f < 0) return 0;
        if(memo[c][f] != -1) return memo[c][f];
        memo[c][f] = t == c;
        for(int i = 0; i < l.size(); i++) {
            if(i == c) continue;
            memo[c][f] = (memo[c][f] + dp(l,t,i, f - abs(l[c] - l[i]))) % mod;
        }
        return memo[c][f];
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(memo, -1, sizeof(memo));
        return dp(locations,finish,start,fuel);
    }
};