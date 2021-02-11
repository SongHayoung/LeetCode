class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());
        int start = 0 , end = nums.size() - 1;
        for(; start < nums.size() && nums[start] == sortedNums[start]; start++) {}
        for(; end >= 0 && nums[end] == sortedNums[end]; end--) {}
        return start > end ? 0 : end - start + 1;
    }
};
