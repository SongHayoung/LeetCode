class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        map<int, int> mp;
        mp[0] = 0;
        int res = 0;
        for(auto& o : order) {
            auto it = prev(mp.upper_bound(o));
            res = max(res, mp[o] = ++it->second);
        }
        return res;
    }
};