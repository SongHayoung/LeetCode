class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int maxVal = nums[0], minVal = nums[0];
        int res = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            int cur = nums[i];
            int tempMaxVal = max(cur, max(maxVal * cur, minVal * cur));
            minVal = min(cur, min(maxVal * cur, minVal * cur));
            
            maxVal = tempMaxVal;
            
            res = max(res, maxVal);
        }

        return res;
    }
};
