class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long, int>> st {{0, -1}};
        int res = INT_MAX;
        long dp = 0;
        for(int i = 0; i < nums.size(); i++) {
            dp += nums[i];
            
            while(!st.empty() and st[0].first <= dp - k)
                res = min(res, i - st[0].second), st.pop_front();

            while(!st.empty() and st.back().first >= dp)
                st.pop_back();
            
            st.push_back({dp, i});
        }
        return res == INT_MAX ? -1 : res;
    }
};