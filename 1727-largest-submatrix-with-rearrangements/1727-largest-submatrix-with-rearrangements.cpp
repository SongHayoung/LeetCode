class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int i, j, k, ans = 0, n = matrix.size(), m = matrix[0].size();
        //열에서 연속되는 칸의 누적을 계산한다.
        for(i = 0; i < m; i++)
            for(j = 1; j < n; j++)
                if(matrix[j][i])
                    matrix[j][i] = matrix[j-1][i] + matrix[j][i];

        //행마다 최대값 순으로 정렬해서         
        for(i = 0; i < n; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for (j = 0; j < m; j++)
                ans = max(ans, (j + 1) * matrix[i][j]);
        }
        return ans;
    }
};