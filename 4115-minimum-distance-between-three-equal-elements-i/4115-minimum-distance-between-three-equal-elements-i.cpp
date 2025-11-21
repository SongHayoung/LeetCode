class Solution {
    int helper(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int res = INT_MAX;
        auto qry = [&](vector<int>& A) {
            if(A.size() < 3) return INT_MAX;
            return 2 * (A[A.size() - 1] - A[A.size() - 3]);
        };
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        for(auto& [k,v] : mp) res = min(res, qry(v));
        return res;
    }
public:
    int minimumDistance(vector<int>& nums) {
        int res = helper(nums);
        reverse(begin(nums), end(nums));
        res = min(res, helper(nums));
        return res == INT_MAX ? -1 : res;
    }
};