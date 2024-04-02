class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int, vector<vector<int>>> mp;
        int cnt = 0;
        for(auto& x : nums1) {
            for(auto& y : nums2) {
                int sum = x + y;
                if(cnt == k and prev(end(mp))->first <= sum) break;
                cnt++;
                mp[sum].push_back({x,y});
                if(cnt > k) {
                    prev(end(mp))->second.pop_back();
                    if(prev(end(mp))->second.size() == 0) {
                        mp.erase(prev(end(mp)));
                    }
                    cnt--;
                }
            }
            if(cnt == k and prev(end(mp))->first <= x + nums2[0]) break;
        }
        vector<vector<int>> res;
        for(auto& [_, vec] : mp) {
            for(auto& v : vec) res.push_back(v);
        }
        return res;
    }
};