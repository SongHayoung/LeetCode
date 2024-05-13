class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = INT_MAX;
        int i = 0, lsum = 0, j = nums.size() - 1, rsum = 0;
        while(i < nums.size() and lsum + nums[i] <= x) lsum += nums[i++];
        if(i == nums.size()) {
            if(lsum == x) return nums.size();
            return -1;
        }
        i--;
        while(i >= 0) {
            while(i <= j and lsum + rsum + nums[j] <= x) {
                rsum += nums[j--];
            }
            if(lsum + rsum == x) {
                res = min(res, i + 1 + (int)nums.size() - j - 1);
            }
            lsum -= nums[i--];
        }
        while(j >= 0 and rsum + nums[j] <= x) rsum += nums[j--];
        if(rsum == x) res = min(res, (int)nums.size() - j - 1);
        
        
        return res == INT_MAX ? -1 : res;
    }
};