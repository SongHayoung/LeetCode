
long long pre[555][555];
bool qry(int y, int x, int k) {
    return k * k == pre[y+1][x+1] - pre[y+1-k][x+1] - pre[y+1][x+1-k] + pre[y+1-k][x+1-k];
}
class Solution {
    bool ok(int n, int m, int k) {
        int minY = INT_MAX, maxY = INT_MIN;
        int minX = INT_MAX, maxX = INT_MIN;
        
        for(int i = k - 1; i < n; i++) {
            for(int j = k - 1; j < m; j++) {
                if(!qry(i,j,k)) continue;
                minY = min(minY, i);
                maxY = max(maxY, i);
                minX = min(minX, j);
                maxX = max(maxX, j);

                if(maxY - minY >= k) return true;
                if(maxX - minX >= k) return true;

            }
        }
        return false;
    }
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            pre[i+1][j+1] = mat[i][j] + pre[i][j+1] + pre[i+1][j] - pre[i][j];
        }
        int res = 0;
        for(; res < min(n,m) and ok(n,m,res+1); res++) {}
        return res * res;
    }
};