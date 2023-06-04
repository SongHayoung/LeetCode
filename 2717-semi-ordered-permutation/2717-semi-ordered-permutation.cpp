class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 1) continue;
            while(i) {
                swap(nums[i-1], nums[i]);
                i -= 1;
                res += 1;
            }
            break;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != nums.size()) continue;
            while(i != nums.size() - 1) {
                swap(nums[i], nums[i+1]);
                i += 1;
                res += 1;
            }
            break;
        }
        return res;
    }
};