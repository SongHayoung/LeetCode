class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long res = 0, sum = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            freq[nums[i]] += 1;
            if(i >= k) {
                sum -= nums[i-k];
                if(--freq[nums[i-k]] == 0) freq.erase(nums[i-k]);
            }
            if(i + 1 >= k and freq.size() >= m) {
                res = max(res, sum);
            }
        }
        return res;
    }
};