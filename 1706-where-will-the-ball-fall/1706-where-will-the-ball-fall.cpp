class Solution {
    int helper(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        for(auto g : grid) {
            int next = g[x] + x;
            if(next == -1 or next == m) return -1;
            if(g[next] != g[x]) return -1;
            x = next;
        }
        return x;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        int m = grid[0].size();
        for(int i = 0; i < m; i++)
            res.push_back(helper(grid,i));
        return res;
    }
};