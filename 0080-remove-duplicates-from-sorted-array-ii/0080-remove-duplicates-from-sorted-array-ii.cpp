class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0, i = 0;
        while(i < nums.size()) {
            int x = nums[i];
            if(i + 1 < nums.size() and nums[i+1] == nums[i]) {
                nums[res] = nums[res+1] = x;
                res += 2;
            } else {
                nums[res] = x;
                res += 1;
            }
            while(i < nums.size() and nums[i] == x) i++;
        }
        return res;
    }
};