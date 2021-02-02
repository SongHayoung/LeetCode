class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;

        vector<int> mins(nums.begin(), nums.end());
        for(int i = 1; i < mins.size(); i++) {
            mins[i] = min(mins[i], mins[i - 1]);
        }
        for(size_t j = nums.size() - 1, k = nums.size(); j >= 0; j--) {
            if(mins[j] >= nums[j]) {
                continue;
            }

            while(k < nums.size() && nums[k] > mins[j])
                ++k;
            if(k < nums.size() && nums[k] < nums[j])
                return true;

            nums[--k] = nums[j];
        }
        return false;
    }
};
