class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1, l = 0, r = 0, n = nums.size();
        auto judge = [&](int p) {
            if(nums[p] == nums[p+1]) return -1;
            return nums[p] < nums[p+1] ? 1 : 0;
        };
        while(l + 1 < n) {
            r = l + 1;
            if(nums[l] != nums[r]) {
                bool inc = judge(l);
                while(r + 1 < n and judge(r) == inc) r++;
                res = max(res, r - l + 1);
            }
            l = r;
        }
        return res;
    }
};