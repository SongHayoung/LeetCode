
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<int> ma(m);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            ma[j] = max(ma[j], A[i][j]);
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(A[i][j] == -1) A[i][j] = ma[j];
        }
        return A;
    }
};
