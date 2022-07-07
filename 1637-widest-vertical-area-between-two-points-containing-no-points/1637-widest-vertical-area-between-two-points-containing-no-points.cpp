class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        int res = 0, n = A.size();
        for(int i = 0; i < n-1; i++) {
            res = max(res, A[i+1][0] - A[i][0]);
        }
        return res;
    }
};