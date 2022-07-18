class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0, n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                matrix[i][j] += matrix[i][j-1];
            
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++)
            for(int j = i; j < m; j++) {
                mp = {{0, 1}};
                int sum = 0;
                for(int k = 0; k < n; k++) {
                    sum += matrix[k][j] - (i ? matrix[k][i - 1] : 0);
                    res += mp[sum - target];
                    mp[sum]++;
                }
            }
        return res;
    }
};