class Solution {
    int helper(vector<int>& A, int n) {
        int res = 0;
        vector<pair<int,int>> st;
        for(int i = 0; i < n; i++) {
            int p = i;
            while(st.size() and st.back().second >= A[i]) {
                auto [at,h] = st.back(); st.pop_back();
                res = max(res, h * (i - at));
                p = at;
            }
            st.push_back({p,A[i]});
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& A) {
        int res = 0, n = A.size(), m = A[0].size();
        vector<int> dp(m+1);
        for(auto& a : A) {
            for(int i = 0; i < m; i++) {
                if(a[i] == '1') dp[i]++;
                else dp[i] = 0;
            }
            res = max(res, helper(dp,m+1));
        }
        return res;
    }
};