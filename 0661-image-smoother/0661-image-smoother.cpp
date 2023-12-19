class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> res(n,vector<int>(m));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            int sum = 0, cnt = 0;
            for(int y = -1; y <= 1; y++) for(int x = -1; x <= 1; x++) {
                if(0 <= i + y and i + y < n and 0 <= j + x and j + x < m) {
                    sum += img[i+y][j+x];
                    cnt += 1;
                }
            }
            res[i][j] = sum / cnt;
        }
        return res;
    }
};
