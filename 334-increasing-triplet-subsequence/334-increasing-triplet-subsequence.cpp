class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //O(n) with greedy
        if(nums.size() <= 2) return false;
        int first = INT_MAX, second = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= first) first = nums[i];
            else if(nums[i] <= second) second = nums[i];
            else return true;
        }

        return false;
    }
};