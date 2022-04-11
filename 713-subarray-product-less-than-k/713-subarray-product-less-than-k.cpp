class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long p = 1;
        int res = 0, n = nums.size();
        for(int l = 0, r = 0; l < n; l++) {
            r = max(r,l);
            while(r < n and p < k)
                p *= nums[r++];
            if(r!=l)
                res += (r - l - (p >= k));
            p /= nums[l];
        }
        return res;
    }
};