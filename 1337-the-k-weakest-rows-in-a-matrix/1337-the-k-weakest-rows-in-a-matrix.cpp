class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, vector<int>> mp;
        int i = 0;
        for(auto r : mat) {
            int s = accumulate(begin(r),end(r),0);
            mp[s].push_back(i++);
        }
        vector<int> res;
        for(auto it = begin(mp); it != end(mp) and k; it++) {
            for(auto r = begin(it->second); r != end(it->second) and k; r++, k--) {
                res.push_back(*r);
            }
        }
        return res;
    }
};