class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(!k) {
            for(int i = 1; i < nums.size(); i++)
                if(!nums[i] && nums[i] == nums[i - 1])
                    return true;
        } else {
            unordered_map<int, int> countOfNums;
            long lNum = (nums[0] %= k);
            countOfNums[lNum]++;
            for (int i = 1; i < nums.size(); i++) {
                nums[i] %= k;
                lNum = (lNum + nums[i]) % k;
                if(!lNum || (nums[i] == nums[i - 1] && !nums[i]))
                    return true;
                if(nums[i]) {
                    countOfNums[lNum]++;
                    if (countOfNums[lNum] >= 2)
                        return true;
                }
            }
        }
        return false;
    }
};