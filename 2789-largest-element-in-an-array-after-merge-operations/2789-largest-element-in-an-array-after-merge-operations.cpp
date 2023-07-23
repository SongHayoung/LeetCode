class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        reverse(begin(nums), end(nums));
        vector<long long> now{nums[0]};
        for(int i = 1; i < nums.size(); i++) {
            if(now.back() >= nums[i]) now.back() += nums[i];
            else now.push_back(nums[i]);
        }
        return *max_element(begin(now), end(now));
    }
};