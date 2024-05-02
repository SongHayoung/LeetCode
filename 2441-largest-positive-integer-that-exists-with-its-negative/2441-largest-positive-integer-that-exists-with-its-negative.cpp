class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> us(begin(nums),end(nums));
        int res = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 and us.count(-nums[i])) res = max(res,nums[i]); 
        }
        return res;
    }
};
