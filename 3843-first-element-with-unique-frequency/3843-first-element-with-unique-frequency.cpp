class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> f;
        for(auto& n : nums) f[n]++;
        unordered_map<int,vector<int>> gf;
        for(auto& [k,v] : f) gf[v].push_back(k);
        unordered_set<int> us;
        for(auto& [k,v] : gf) if(v.size() == 1) us.insert(v[0]);
        if(us.size() == 0) return -1;
        for(int i = 0; i < nums.size(); i++) {
            if(!us.count(nums[i])) continue;
            return nums[i];
        }
        return -1;
    }
};