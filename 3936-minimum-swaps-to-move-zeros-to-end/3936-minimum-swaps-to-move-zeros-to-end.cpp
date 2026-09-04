class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zero = count(begin(nums), end(nums), 0), res = 0;
        for(int i = nums.size() - zero - 1; i >= 0; i--) if(!nums[i]) res++;
        return res;
    }
};