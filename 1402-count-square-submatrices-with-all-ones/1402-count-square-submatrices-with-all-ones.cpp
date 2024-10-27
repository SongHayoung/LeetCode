class Solution {
    int helper(vector<int>& A, int n) {
        vector<pair<int,int>> st;
        int res = 0;
        for(int i = 0; i < n; i++) {
            int p = i;
            while(st.size() and st.back().second > A[i]) {
                auto [at,h] = st.back(); st.pop_back();
                int w = (i - at), nxt = st.size() ? st.back().second : 0;
                nxt = max(nxt, A[i]);
                while(h > nxt) {
                    res += max(0, w - h + 1);
                    h--;
                }
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
    int countSquares(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size(), res = 0;
        vector<int> dp(m+1);
        for(auto& a : A) {
            for(int i = 0; i < m; i++) {
                if(a[i]) dp[i]++;
                else dp[i] = 0;
            }
            res += helper(dp,m+1);
        }
        return res;
    }
};