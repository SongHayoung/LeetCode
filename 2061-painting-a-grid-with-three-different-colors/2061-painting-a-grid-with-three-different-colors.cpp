class Solution {
    //m, n, up color, left color
    int dp[1001][1000];
    vector<int> comb[1000];
    int N, M;
    int mod = 1e9 + 7;

    int getColorAt(int mask, int i) {
        if(i < 0) return 0;
        return (mask>>(i * 2)) & 3;
    }
    bool verifyBoth(int comb1, int comb2) {
        for(int i = 0; i < M; i++) {
            if(getColorAt(comb1, i) == getColorAt(comb2, i)) return false;
        }
        return true;
    }
    bool verifySelf(int comb) {
        for(int i = 0; i < M; i++) {
            if(getColorAt(comb,i) == 0) return false;
            if(getColorAt(comb, i - 1) == getColorAt(comb, i)) return false;
        }
        return true;
    }

    void buildComb() {
        for(int i = 1; i < 1<<(M*2); i++) {
            if(verifySelf(i))
                comb[0].push_back(i);
        }
        for(int i = 0; i < comb[0].size(); i++) {
            for(int j = i + 1; j < comb[0].size(); j++) {
                if(verifyBoth(comb[0][i], comb[0][j])) {
                    comb[comb[0][i]].push_back(comb[0][j]);
                    comb[comb[0][j]].push_back(comb[0][i]);
                }
            }
        }
    }
    int helper(int y, int colors) {
        if(y == N) return 1;

        if(dp[y][colors] != -1) {
            return dp[y][colors];
        }
        int& res = dp[y][colors] = 0;

        for(auto c : comb[colors]) {
            res = (res + helper(y + 1, c)) % mod;
        }
        return res;
    }
public:
    int colorTheGrid(int m, int n) {
        memset(dp,-1,sizeof(dp));
        N = n, M = m;
        buildComb();
        return helper(0,0);
    }
};