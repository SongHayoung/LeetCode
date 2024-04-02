class Solution {
    int helper(vector<int>& A) {
        int res = 0;
        vector<pair<int, int>> st;
        for(int i = 0; i < A.size(); i++) {
            int pos = i;
            while(st.size() and st.back().second >= A[i]) {
                auto [at, h] = st.back(); st.pop_back();
                int d = i - at;
                res = max(res, min(d, h));
                pos = at;
            }
            st.push_back({pos, A[i]});
            res = max(res, min(i - pos + 1, A[i]));
        }
        for(int i = 0; i < st.size() - 1; i++) {
            auto [at, h] = st[i];
            int d = st.back().first - at + 1;
            res = max(res, min(d,h));
        }
        return res * res;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix[0].size(), res = 0;
        vector<int> dp(m);
        for(auto& r : matrix) {
            for(int i = 0; i < m; i++) {
                if(r[i] == '0') dp[i] = 0;
                else dp[i]++;
            }
            res = max(res, helper(dp));
        }
        return res;
    }
};