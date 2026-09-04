class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> res(nums.size());
        int parity[2]{0,};
        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] = parity[!(nums[i]&1)];
            parity[nums[i]&1]++;
        }
        return res;
    }
};