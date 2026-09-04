class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size(), mid = n / 2;
        for(int i = 0; i < n; i++) {
            if(i == mid) continue;
            if(nums[i] == nums[mid]) return false;
        }
        return true;
    }
};