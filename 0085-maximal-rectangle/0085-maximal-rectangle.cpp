class Solution {
    int helper(vector<int>& A) {
        int res = 0, n = A.size();
        vector<pair<int,int>> st;
        for(int i = 0; i < n; i++) {
            int h = A[i], pos = i;
            while(st.size() and st.back().first >= h) {
                res = max(res, st.back().first * (i - st.back().second));
                pos = st.back().second;
                st.pop_back();
            }
            st.push_back({h,pos});
        }
        for(int i = 0; i < st.size(); i++) res = max(res, st[i].first * (n - st[i].second));
        return res;
    }
public:
    int mostComplexTerrain(vector<vector<int>>& terrain) {
        int n = terrain.size(), m = terrain[0].size(), res = 0;
        vector<int> dp(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(terrain[i][j]) dp[j]++;
                else dp[j] = 0;
            }
            res = max(res, helper(dp));
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> mat(n,vector<int>(m));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) mat[i][j] = matrix[i][j] - '0';
        return mostComplexTerrain(mat);
    }
};