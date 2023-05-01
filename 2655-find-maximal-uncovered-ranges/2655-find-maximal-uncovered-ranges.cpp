class Solution {
    map<int, int> range;
    void add(int s, int e) {
        if(!range.count(s)) range[s] = -1;
        range[s] = max(range[s], e);
        auto it = range.lower_bound(s);
        if(it != begin(range) and prev(it)->second + 1 >= s) {
            prev(it)->second = max(prev(it)->second, e);
            it = prev(it);
        }
        while(next(it) != end(range) and it->second + 1 >= next(it)->first) {
            it->second = max(it->second, next(it)->second);
            range.erase(next(it));
        }
    }
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {
        range.clear();
        add(-1,-1);
        add(n,n);
        for(auto r : ranges) {
            add(r[0],r[1]);
        }
        vector<vector<int>> res;
        for(auto it = begin(range); next(it) != end(range); it++) {
            int l = it->second + 1, r = next(it)->first - 1;
            if(0 <= l and l <= n and 0 <= r and r <= n) res.push_back({l,r});
        }
        return res;
    }
};