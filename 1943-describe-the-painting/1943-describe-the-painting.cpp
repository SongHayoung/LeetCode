class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> mp;
        for(auto& seg : segments) {
            int l = seg[0], r = seg[1], c = seg[2];
            mp[l] += c;
            mp[r] -= c;
        }
        vector<vector<long long>> res;
        int left = 0;
        for(auto& [k, v] : mp) {
            if(mp[left] > 0) {
                res.push_back({left, k, mp[left]});
            }
            mp[k] += mp[left];
            left = k;
        }
        return res;
    }
};