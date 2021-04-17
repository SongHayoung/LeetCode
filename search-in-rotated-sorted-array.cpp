class Solution {
    int search(vector<int>& nums, int target, int start, int end) {
        if(start == end) return nums[start] == target ? start : -1;
        int mid = (start + end) / 2;
        if(nums[start] <= nums[mid] && nums[start] <= target && target <= nums[mid]) {
            auto it = lower_bound(nums.begin() + start, nums.begin() + mid, target);
            return *it == target ? it - nums.begin() : -1;
        }
        if(nums[mid + 1] <= nums[end] && nums[mid + 1] <= target && target <= nums[end]) {
            auto it = lower_bound(nums.begin() + mid + 1, nums.begin() + end, target);
            return *it == target ? it - nums.begin() : -1;
        }
        if(nums[mid + 1] <= nums[end])
            return search(nums, target, start, mid);
        return search(nums, target, mid + 1, end);
    }
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};
