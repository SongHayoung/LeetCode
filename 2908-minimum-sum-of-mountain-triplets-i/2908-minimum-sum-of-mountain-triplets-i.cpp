class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), lmi = 1e9, rmi = 1e9;
        vector<long long> dpl(n,1e9), dpr(n,1e9);
        for(int i = 0; i < n; i++) {
            if(nums[i] > lmi) dpl[i] = lmi;
            lmi = min(nums[i], lmi);
        }
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] > rmi) dpr[i] = rmi;
            rmi = min(nums[i], rmi);
        }
        long long res = 1e9;
        for(int i = 0; i < n; i++) {
            res = min(res, dpl[i] + dpr[i] + nums[i]);
        }
        return res >= 1e9 ? -1:res;
    }
};

