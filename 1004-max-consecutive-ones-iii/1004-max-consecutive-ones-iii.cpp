class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, z = 0, n = nums.size(), res = 0;
        while(r < n) {
            if(nums[r++] == 0) z++;
            while(z > k) {
                if(nums[l++] == 0) z--;
            }
            res = max(res, r - l);
        }
        return res;
    }
};