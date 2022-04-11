class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long acc = 0, res = 0, tot = 0, sz = nums.size();
        for(int i = 0; i < sz; i++) {
            acc += nums[i];
            tot += i * nums[i];
        }
        res = tot;
        for(int i = 0; i < sz; i++) {
            tot = tot + acc - sz * nums[sz - 1 - i];
            res = max(tot, res);
        }

        return res;
    }
};