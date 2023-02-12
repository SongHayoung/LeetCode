class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            if(l == r) {
                res += nums[l];
            } else {
                res += stoll(to_string(nums[l]) + to_string(nums[r]));
            }
            l += 1, r -= 1;
        }
        return res;
    }
};
