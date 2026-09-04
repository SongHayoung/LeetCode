class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long> res(n, nums[0]);
        long long best = 0;
        for(int i = 1; i < n; i++) {
            res[i] = max(res[i], 1ll * nums[i]);
            if(i - 2 >= 0) best = max(best, res[i-2]);
            res[i] = max(res[i], nums[i] + best);
            if(colors[i] != colors[i-1]) {
                res[i] = max(res[i], nums[i] + res[i-1]);
                best = max(best, res[i-1]);
            }
        }
        return *max_element(begin(res), end(res));
    }
};
