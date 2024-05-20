class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long r = 0, l = accumulate(begin(nums), end(nums), 0ll);
        int res = 0, n = nums.size();
        for(int i = n - 1; i >= 1; i--) {
            r += nums[i];
            l -= nums[i];
            if(l >= r) res++;
        }
        return res;
    }
};