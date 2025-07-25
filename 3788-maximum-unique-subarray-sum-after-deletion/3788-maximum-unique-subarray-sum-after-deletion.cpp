class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = *max_element(begin(nums), end(nums)), n = nums.size(), sum = 0;
        unordered_set<int> us;
        for(int i = 0; i < n; i++) {
            if(us.count(nums[i])) continue;
            us.insert(nums[i]);
            sum += max(0,nums[i]);
        }
        return sum > 0 ? sum : res;
    }
};