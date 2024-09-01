class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxScore = 0;

        for (int mask = 0; mask < (1 << m); ++mask) {
            set<int> selected;
            bool valid = true;
            int currentScore = 0;

            for (int i = 0; i < n; ++i) {
                int maxVal = -1;
                for (int j = 0; j < m; ++j) {
                    if (mask & (1 << j)) {
                        if (selected.count(grid[i][j])) {
                            valid = false;
                            break;
                        }
                        maxVal = max(maxVal, grid[i][j]);
                    }
                }
                if (!valid) break;
                if (maxVal != -1) {
                    currentScore += maxVal;
                    selected.insert(maxVal);
                }
            }

            if (valid) {
                maxScore = max(maxScore, currentScore);
            }
        }

        return maxScore;
    }
};