class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res;
        for(int i = 0; i <= n - k; i++) {
            res.emplace_back();
            for(int j = 0; j <= m - k; j++) {
                vector<int> S;
                for(int ii = i; ii < i + k; ii++) {
                    for(int jj = j; jj < j + k; jj++) {
                        S.push_back(grid[ii][jj]);
                    }
                }
                sort(begin(S), end(S));
                S.erase(unique(begin(S), end(S)), end(S));
                if(S.size() == 1) res.back().push_back(0);
                else {
                    int mi = INT_MAX;
                    for(int i = 1; i < S.size(); i++) {
                        mi = min(mi, S[i] - S[i-1]);
                    }
                    res.back().push_back(mi);
                }
            }
        }
        return res;
    }
};