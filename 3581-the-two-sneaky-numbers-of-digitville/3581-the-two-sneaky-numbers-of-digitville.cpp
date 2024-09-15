class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int idx = nums[i] % n;
            nums[idx] += n;
            if(nums[idx] / n == 2) {
                res.push_back(idx);
            }
        }
        return res;
    }
};