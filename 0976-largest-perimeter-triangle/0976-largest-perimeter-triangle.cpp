class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0, l = 0, r = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 2; i--) {
            //nums[l] + nums[m] > nums[r]
            if(nums[i-2] + nums[i-1] > nums[i]) {
                return nums[i-2]+nums[i-1]+nums[i];
            }
        }
        
        return 0;
    }
};