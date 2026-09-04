class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++) res[i] = accumulate(begin(matrix[i]), end(matrix[i]), 0);
        return res;
    }
};