class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int res = 0;
        for(int i = 0, fl = 1; i < nums.size(); i++, fl = -fl) {
            res += fl * nums[i];
        }
        return res;
    }
};