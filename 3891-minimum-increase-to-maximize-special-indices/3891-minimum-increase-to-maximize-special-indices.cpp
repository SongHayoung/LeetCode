
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        auto cost = [&](int i) {
            return max({0ll, nums[i-1] - nums[i] + 1ll, nums[i+1] - nums[i] + 1ll});
        };
        if(n & 1) {
            long long res = 0;
            for(int i = 1; i < n; i += 2) res += cost(i);
            return res;
        }
        vector<vector<long long>> pre(2, vector<long long>(n));
        for(int i = 1; i < n - 1; i++) pre[i&1][i] = cost(i);
        for(int i = 1; i < n; i++) pre[1][i] += pre[1][i-1];
        for(int i = n - 2; i >= 0; i--) pre[0][i] += pre[0][i+1];
        long long res = min({pre[0][0], pre[1][n-1]});
        for(int i = 1; i < n - 2; i += 2) {
            res = min(res, pre[1][i] + pre[0][i+2]);
        }
        return res;
    }
};
