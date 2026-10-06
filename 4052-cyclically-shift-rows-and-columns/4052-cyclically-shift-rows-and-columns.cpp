
class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        auto work = [&](int cnt, int at, bool row) {
            if(!cnt) return;
            vector<int> A;
            for(int i = 0; i < n; i++) {
                A.push_back(grid[row ? at : i][!row ? at : i]);
            }
            for(int i = 0; i < n; i++) {
                grid[row ? at : i][!row ? at : i] = A[(i + cnt) % n];
            }
        };
        for(int i = 0; i < n; i++) work(rowShift[i], i, true);
        for(int i = 0; i < n; i++) work(colShift[i], i, false);
        return grid;
    }
};