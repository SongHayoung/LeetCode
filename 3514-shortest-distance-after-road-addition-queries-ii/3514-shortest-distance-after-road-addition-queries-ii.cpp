class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        map<int,int> mp;
        vector<int> res;
        for(int i = 0; i < n - 1; i++) mp[i] = i + 1;
        int now = n - 1;
        for(auto& q : queries) {
            int u = q[0], v = q[1];
            
            if(mp.count(u) and mp[u] < v) {
                auto it = mp.lower_bound(u);
                    it->second = v;
                    auto nit = next(it);
                    while(nit != end(mp) and nit->first < v) {
                        now -= 1;
                        auto nnit = next(nit);
                        mp.erase(nit);
                        nit = nnit;
                    }
            }
           
            res.push_back(now);
        }
        return res;
    }
};