class Solution {
    int dfs(int n, int cur = 0, int q = 0, int diagonal = 0, int antiDiagonal = 0, int res = 0) {
        if(cur == n) return 1;
        for(int i = 0; i < n; i++) {
            if (!((q & (1<<i)) || (diagonal & (1<<i)) || (antiDiagonal & (1<<i))))
                res += dfs(n, cur + 1, q ^ (1<<i), (diagonal ^ (1<<i)) << 1, (antiDiagonal ^ (1<<i)) >> 1);
        }
        return res;
    }
public:
    int totalNQueens(int n) {
        return dfs(n);
    }
};