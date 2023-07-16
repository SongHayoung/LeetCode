class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 1; i <= nums.size(); i++) {
            if(n % i) continue;
            res += nums[i-1] * nums[i-1];
        }
        return res;
    }
};
