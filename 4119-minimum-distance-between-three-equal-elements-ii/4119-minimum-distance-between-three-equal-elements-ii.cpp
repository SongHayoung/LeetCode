class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int res = INT_MAX;
        auto qry = [&](vector<int>& A) {
            if(A.size() < 4) return INT_MAX;
            return 2 * (A[A.size() - 1] - A[A.size() - 3]);
        };
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
            res = min(res, qry(mp[nums[i]]));
        }
        for(auto& [k,v] : mp) {
            if(v.size() == 3) res = min(res,2 * (v[2] - v[0]));
        }
        return res == INT_MAX ? -1 : res;
    }
};
