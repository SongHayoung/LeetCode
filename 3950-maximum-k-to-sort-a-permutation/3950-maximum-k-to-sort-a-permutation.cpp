class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                res &= i;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};