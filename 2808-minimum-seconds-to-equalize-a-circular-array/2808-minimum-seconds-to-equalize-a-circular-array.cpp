class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);
        for(auto& [k,vec] : mp) {
            int ma = 0;
            for(int i = 0; i < vec.size(); i++) {
                if(i + 1 == vec.size()) {
                    ma = max(ma, vec[0] + (int)nums.size() - 1 - vec[i]);
                } else ma = max(ma, vec[i+1] - vec[i] - 1);
            }
            res = min(res, (ma + 1) / 2);
        }
        return res;
    }
}; 