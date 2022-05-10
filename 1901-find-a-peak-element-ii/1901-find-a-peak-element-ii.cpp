class Solution {
    bool bigger(vector<vector<int>>& mat, int y, int x) {
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(0 <= ny and ny < n and 0 <= nx and nx < m and mat[ny][nx] >= mat[y][x]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), i = 0;
        while(true) {
            int l = 0, r = m - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(mid + 1 < m and mat[i][mid + 1] >= mat[i][mid])
                    l = mid + 1;
                else if(mid - 1 >= 0 and mat[i][mid - 1] >= mat[i][mid])
                    r = mid - 1;
                else if(i + 1 < n and mat[i + 1][mid] >= mat[i][mid])
                    i += 1;
                else if(i - 1 >= 0 and mat[i - 1][mid] >= mat[i][mid])
                    i -= 1;
                else return {i, mid};
            }
        }
        return {};
    }
};