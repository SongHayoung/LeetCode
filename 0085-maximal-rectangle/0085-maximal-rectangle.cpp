class Solution {
    int helper(vector<int>& A) {
        vector<pair<int, int>> st;
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            int at = i;
            while(st.size() and st.back().second >= A[i]) {
                auto [pos, h] = st.back(); st.pop_back();
                res = max(res, (i - pos) * h);
                at = pos;
            }
            st.push_back({at, A[i]});
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size() + 1);
        int res = 0;
        for(auto& r : matrix) {
            for(int i = 0; i < r.size(); i++) {
                if(r[i] == '0') dp[i] = 0;
                else dp[i]++;
            }
            res = max(res, helper(dp));
        }
        return res;
    }
};