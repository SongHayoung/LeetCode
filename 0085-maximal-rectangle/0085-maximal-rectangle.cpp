class Solution {
    int helper(vector<int>& A) {
        int res = 0, n = A.size();
        vector<pair<int,int>> st;

        for(int i = 0; i < n; i++) {
            int at = i;
            while(st.size() and st.back().second >= A[i]) {
                int h = st.back().second;
                int w = i - st.back().first;
                res = max(res, h * w);
                at = st.back().first;
                st.pop_back();
            }
            st.push_back({at,A[i]});
        }
        for(auto& [at,h] : st) {
            res = max(res, h * (n - at));
        }
        
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0, n = matrix.size(), m = matrix[0].size();
        vector<int> dp(m);
        for(auto& row : matrix) {
            for(int i = 0; i < m; i++) {
                if(row[i] == '1') dp[i]++;
                else dp[i] = 0;
            }
            res = max(res, helper(dp));
        }
        return res;
    }
};