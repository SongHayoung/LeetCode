class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> l(4, vector<int>(n, n + 1));
        vector<vector<int>> r(4, vector<int>(n, n + 1));
        
        for(int c = 1; c <= 3; c++) {
            r[colors[n-1]][n-1] = l[colors[0]][0] = 0; //init
            for(int i = 1; i < n; i++) {
                l[c][i] = colors[i] == c ? 0 : l[c][i-1] + 1;
                r[c][n-i-1] = colors[n-i-1] == c ? 0 : r[c][n-i] + 1;
            }
        }
        
        vector<int> res;
        for(auto q : queries) {
            int ans = min(l[q[1]][q[0]], r[q[1]][q[0]]);
            if(ans >= n + 1) ans = -1;
            res.push_back(ans);
        }
        return res;
    }
};