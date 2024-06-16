
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(begin(nums), end(nums));
        long long sum = 0, res = 0;
        for(int i = 0; i < nums.size() and sum < n and nums[i] <= n; i++) {
            while(sum + 1 < nums[i]) {
                sum = sum + sum + 1;
                res++;
            }
            sum += nums[i];
        }
        while(sum < n) {
            sum = sum + sum + 1;
            res++;
        }
        return res;
    }
};