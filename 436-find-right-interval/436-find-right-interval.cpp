class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& I) {
        int n = I.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[I[i][0]] = i;
        }
        vector<int> res(n, -1);
        for(int i = 0; i < n; i++) {
            auto it = mp.lower_bound(I[i][1]);
            res[i] = it == end(mp) ? -1 : it->second;
        }
        
        return res;
    }
};