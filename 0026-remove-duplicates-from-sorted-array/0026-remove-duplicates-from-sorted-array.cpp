class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            bool pass = true;
            for(int j = 0; j < last; j++) {
                if(nums[j] == nums[i]) pass = false;
            }
            if(pass) {
                nums[last] = nums[i];
                last += 1;
            }
        }
        return last;
    }
};