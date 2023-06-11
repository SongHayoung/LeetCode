class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long res = 0, n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++) res += nums[i], sum += nums[i];
        for(int r = 1; r <= n; r++) {
            vector<int> A(n);
            for(int i = 0; i < n; i++) {
                sum -= nums[i];
                A[i] = min(nums[i], nums[(i+1) % n]);
                sum += A[i];
            }
            sum += x;
            swap(A,nums);
            res = min(res, sum);
        }
        return res;
    }
};