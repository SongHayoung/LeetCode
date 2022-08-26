class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int sum = 0;
        for(auto& n : nums) {
            if(n % 2 == 0) sum += n;
        }
        for(auto& q : queries) {
            int v = q[0], idx = q[1];
            if(nums[idx] % 2 == 0) sum -= nums[idx];
            nums[idx] += v;
            if(nums[idx] % 2 == 0) sum += nums[idx];
            res.push_back(sum);
        }
        return res;
    }
};