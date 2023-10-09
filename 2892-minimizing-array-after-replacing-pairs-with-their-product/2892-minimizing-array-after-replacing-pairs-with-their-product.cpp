class Solution {
public:
    int minArrayLength(vector<int>& nums, int k) {
        int res = 0, p = 0;
        while(p < nums.size()) {
            long long x = nums[p++];
            while(p < nums.size() and x * nums[p] <= k) x *= nums[p++];
            res += 1;
            if(x == 0) return 1;
        }
        return res;
    }
};