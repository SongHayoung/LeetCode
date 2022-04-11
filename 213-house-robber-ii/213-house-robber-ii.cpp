class Solution {
public:
    int rob(vector<int>& nums) {
        int odd = 0, even = nums[0], afterOdd = 0, afterEven = 0;
        for(int i = 1; i < nums.size() - 1; i++) {
            if(i & 1) {
                odd = max(odd + nums[i], even);
                afterOdd = max(afterOdd + nums[i], afterEven);
            }
            else {
                even = max(odd, even + nums[i]);
                afterEven = max(afterEven + nums[i], afterOdd);
            }
        }
        if((nums.size() - 1) & 1) {
            afterOdd = max(afterOdd + nums.back(), afterEven);
        } else {
            afterEven = max(afterEven + nums.back(), afterOdd);
        }
        return max({odd, even, afterOdd, afterEven});
    }
};