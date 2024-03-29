class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 1; i < n; i++) {
	matrix[i][0] = matrix[i][0] + min(matrix[i-1][0], matrix[i-1][1]);
	for(int j = 1; j < m - 1; j ++) {
	matrix[i][j] = matrix[i][j] + min({matrix[i-1][j], matrix[i-1][j-1], matrix[i-1][j+1]});
	}
	matrix[i][m-1] = matrix[i][m-1] + min(matrix[i-1][m-1], matrix[i-1][m-2]);
        }
      return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};
