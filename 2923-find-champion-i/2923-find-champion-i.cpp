class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < grid[i].size(); j++) cnt += grid[i][j];
            if(cnt == grid[i].size() - 1) return i;
        }
        return -1;
    }
};