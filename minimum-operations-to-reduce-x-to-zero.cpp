class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sz = nums.size();
        int left = 0, right = sz - 1;
        int val = 0, res = INT_MAX;
        for(; left < sz && val + nums[left] <= x; left++) {
                val += nums[left];
        }
        
        if(left == sz)
            return val == x ? left : -1;
        
        while(right != -1) {
            if(val == x) {
                res = min(res, left + sz - right - 1);
            }
            
            if(right && val + nums[right] <= x) {
                val += nums[right--];
            } else if(left){
                val -= nums[--left];
            } else {
                break;
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
