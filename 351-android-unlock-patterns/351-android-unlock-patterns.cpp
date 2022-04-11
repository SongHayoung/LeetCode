class Solution {
    //k, left, lastpick, pattern
    unordered_map<int, vector<pair<int,int>>> blocks {
        {1, {{3,2},{7,4},{9,5}}},
        {2, {{8,5}}},
        {3, {{1,2},{7,5},{9,6}}},
        {4, {{6,5}}},
        {6, {{4,5}}},
        {7, {{1,4},{3,5},{9,8}}},
        {8, {{2,5}}},
        {9, {{7,8},{3,6},{1,5}}},
    };
    int dp[10][10][1<<11];
    int getBlockTarget(int from, int to) {
        for(auto [k, v]: blocks[from]) {
            if(k == to) return v;
        }
        return -1;
    }
    int solution(int left, int cur, int mask) {
        if(!left) return 1;
        if(dp[left][cur][mask] != -1) return dp[left][cur][mask];
        int& res = dp[left][cur][mask] = 0;

        for(int i = 1; i <= 9; i++) {
            if(mask & (1<<(i-1))) continue;
            int blockTarget = getBlockTarget(cur, i);
            if(blockTarget == -1 or (mask & (1<<(blockTarget-1)))) {
                res += solution(left-1,i,mask | (1<<(i-1)));
            }
        }
        return res;
    }
public:
    int numberOfPatterns(int m, int n) {
        memset(dp,-1,sizeof(dp));
        int res = 0;
        for(int i = m; i <= n; i++) {
            for(int cur = 1; cur <= 9; cur++) {
                res += solution(i-1,cur,1<<(cur-1));
            }
        }
        return res;
    }
};