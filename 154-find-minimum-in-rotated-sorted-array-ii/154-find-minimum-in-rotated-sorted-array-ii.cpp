class Solution {
    int binarySearch(vector<int>& nums, int l, int r) {
        if(l + 1 >= r) return min(nums[l], nums[r]);
        int m = (l + r) / 2;
        if(nums[l] < nums[m]) {
            if(nums[m] > nums[r]) return binarySearch(nums, m, r);
            return binarySearch(nums, l, m);
        }
        if(nums[l] == nums[r]) {
            if(nums[m] > nums[r]) return binarySearch(nums, m, r);
            if(nums[r] == nums[m]) return min(binarySearch(nums, l, m), binarySearch(nums, m, r));
            return binarySearch(nums, l, m);
        }
        if(nums[m] > nums[r]) return binarySearch(nums, m, r);
        return binarySearch(nums, l, m);
        
    }
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};