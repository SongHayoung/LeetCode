class Solution {
    vector<int> manacher(vector<long long>& s) {
        vector<int> dp(s.size());
        for(int i = 0, l = 0, r = -1; i < s.size(); i++) {
            dp[i] = max(0, min(r - i, r + l - i >= 0 ? dp[r + l - i] : -1));
            while(i + dp[i] < s.size() and i - dp[i] >= 0 and s[i-dp[i]] == s[i+dp[i]]) dp[i]++;
            if(r < i + dp[i]) {
                r = i + dp[i];
                l = i - dp[i];
            }
        }
        return dp;
    }
public:
    long long getSum(vector<int>& nums) {
        vector<long long> A{0}, pre{0,0};
        for(int i = 0; i < nums.size(); i++) {
            A.push_back(nums[i]);
            pre.push_back(pre.back() + nums[i]);
            
            A.push_back(0);
            pre.push_back(pre.back());
        }
        vector<int> pos = manacher(A);
        long long res = -1;
        for(int i = 0; i < A.size(); i++) {
            int l = i - pos[i] + 1, r = i + pos[i];
            res = max(res, pre[r] - pre[l]);
        }
        return res;
    }
};