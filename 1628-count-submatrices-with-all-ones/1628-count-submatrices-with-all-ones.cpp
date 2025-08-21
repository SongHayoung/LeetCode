class Solution {
    int helper(vector<int>& A, int n) {
        vector<pair<int,int>> st;
        int res = 0;
        for(int i = 0; i < n; i++) {
            int p = i;
            while(st.size() and st.back().second > A[i]) {
                auto [at,h] = st.back(); st.pop_back();
                int len = i - at;
                res += len * (len + 1) / 2 * (h - max(A[i], st.size() ? st.back().second : 0));
                p = at;
            }
            while(st.size() and st.back().second == A[i]) {
                auto [at,h] = st.back(); st.pop_back();
                p = at;
            }
            st.push_back({p,A[i]});
        }
        return res;
    }
public:
    int numSubmat(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size(), res = 0;
        vector<int> dp(m+1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j]) dp[j]++;
                else dp[j] = 0;
            }
            res += helper(dp,m+1);
        }
        return res;
    }
};