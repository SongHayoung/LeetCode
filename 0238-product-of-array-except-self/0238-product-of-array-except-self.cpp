class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long product = 1, sz = nums.size();
        set<int> zero;
        vector<int> res(sz, 0);
        for(int i = 0; i < sz; i++) {
            if(nums[i]) product *= nums[i];
            else zero.insert(i);
        }

        if(zero.size() >= 2) return res;
        else if(zero.size() == 1) {
            res[*zero.lower_bound(0)] = product;
            return res;
        }
        for(int i = 0; i < sz; i++) {
            res[i] = product / nums[i];
        }
        return res;
    }
};