class Solution {
    vector<vector<int>> res;
    void helper(unordered_map<int,int>& mp, int n, vector<int>& perm) {
        if(!n) {
            res.push_back(perm);
        } else {
            for(auto [k, v]: mp) {
                if(!v) continue;
                mp[k]--;
                perm.push_back(k);
                helper(mp,n-1,perm);
                perm.pop_back();
                mp[k]++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto& n : nums)
            mp[n]++;
        helper(mp, nums.size(), vector<int>() = {});
        return res;
    }
};