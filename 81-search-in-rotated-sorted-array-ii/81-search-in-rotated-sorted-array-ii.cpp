class Solution {
    bool recursiveBinarySearch(vector<int>& nums, int start, int end, int target) {
        if(start + 1 >= end)
            return nums[start] == target || nums[end] == target;
        int mid = (start + end)>>1;
        if(nums[start] < nums[mid] && nums[start] <= target && target <= nums[mid])
            return *lower_bound(nums.begin() + start, nums.begin() + mid, target) == target;
        if(nums[mid + 1] < nums[end] && nums[mid + 1] <= target && target <= nums[end])
            return *lower_bound(nums.begin() + mid + 1, nums.begin() + end, target) == target;
        if(nums[start] < nums[mid] && nums[mid] < target)
            return recursiveBinarySearch(nums, mid + 1, end, target);

        return recursiveBinarySearch(nums, start, mid, target) || recursiveBinarySearch(nums, mid + 1, end, target);


    }
public:
    bool search(vector<int>& nums, int target) {
        return recursiveBinarySearch(nums, 0, nums.size() - 1, target);
    }
};
