class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int res = 0;
        for(auto [_,vec] : mp) {
            int l = 0, r = 0;
            while(r < vec.size()) {
                while(r < vec.size()) {
                    int cnt = r - l + 1;
                    int skip = vec[r] - vec[l] + 1 - cnt;
                    if(skip <= k) {
                        res = max(res, cnt);
                        r += 1;
                    } else break;
                }
                l += 1;
            }
        }
        return res;
    }
};