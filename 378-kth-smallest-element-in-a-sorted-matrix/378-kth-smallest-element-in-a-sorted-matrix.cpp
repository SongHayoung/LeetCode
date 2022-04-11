class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back(), n = matrix.size();
        while(l < r) {
            int m = l + (r - l) / 2, cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
            }
            if(cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
};