class Solution {
    int left(vector<vector<int>>& A, int i, int j, int n, int m) {
        i -= 1, j -= 1;
        unordered_set<int> us;
        while(i >= 0 and j >= 0) {
            us.insert(A[i][j]);
            i -= 1, j -= 1;
        }
        return us.size();
    }
    int right(vector<vector<int>>& A, int i, int j, int n, int m) {
        i += 1, j += 1;
        unordered_set<int> us;
        while(i < n and j < m) {
            us.insert(A[i][j]);
            i += 1, j += 1;
        }
        return us.size();
    }
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> res(n,vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i][j] = abs(left(A,i,j,n,m) - right(A,i,j,n,m));
            }
        }
        return res;
    }
};