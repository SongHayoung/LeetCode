class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        int le = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(le * 2 + nums[i] == sum) return i;
            le += nums[i];
        }
        return -1;
    }
};