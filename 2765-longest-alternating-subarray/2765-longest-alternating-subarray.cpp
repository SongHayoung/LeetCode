class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int res = -1, l = 0, r = 0, n = nums.size();
        while(l < n) {
            if(l + 1 < n and nums[l] + 1 == nums[l + 1]) {
                int a = nums[l], b = nums[l+1], cnt = 0;
                while(l < n) {
                    if(nums[l] == a) cnt += 1;
                    else break;
                    swap(a,b);
                    l += 1;
                }
                res = max(res, cnt);
                l -= 1;
            } else l += 1;
        }
        return res;
    }
};