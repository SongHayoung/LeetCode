class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i + 2 < nums.size(); ) {
            int d = nums[i] - nums[i+1], j = i + 1;
            for(; j + 1 < nums.size() and nums[j] - nums[j+1] == d; j++) {}
            if(j - i >= 2) {
                int x = j - i - 1;
                
                res += x * (x + 1) / 2;
            }
            i = j;
        }
        return res;
    }
};