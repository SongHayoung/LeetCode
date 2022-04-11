class Solution {
    int helper(vector<int>& nums) {
        vector<pair<int,int>> st;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int index = i;
            while(!st.empty() and st.back().second >= nums[i]) {
                index = st.back().first;
                res = max(res, st.back().second * (i - st.back().first));
                st.pop_back();
            }
            st.push_back({index, nums[i]});
            res = max(res, nums[i]);
        }
        
        for(int i = 0; i < st.size(); i++) {
            res = max(res, st[i].second * ((int)nums.size() - st[i].first));
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix[0].size(), res = 0;
        vector<int> dp(m, 0);
        for(auto row : matrix) {
            for(int i = 0; i < m; i++) {
                if(row[i] == '0') dp[i] = 0;
                else dp[i] += 1;
            }
            res = max(res, helper(dp));
        }
        return res;
    }
};