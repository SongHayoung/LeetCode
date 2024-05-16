class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        int neg = 0, who = 0, ord = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == -1) {
                if(who < 0) ans.push_back(-1);
                else ans.push_back(nums[who]);
                who--;
            } else {
                swap(nums[neg],nums[i]);
                who = neg++;
            }
        }
        return ans;
    }
};