class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        unordered_map<int, pair<int, int>> mp;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) mp[A[i][j]] = {i,j};
        vector<int> row(n), col(m);
        int rsum = 0, csum = 0;
        for(int i = 0; i < arr.size(); i++) {
            auto [y,x] = mp[arr[i]];
            if(++row[y] == m) return i;
            if(++col[x] == n) return i;
        }
        return arr.size();
    }
};