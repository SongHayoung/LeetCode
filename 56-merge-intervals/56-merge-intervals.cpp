class Solution {
    map<int, int> range;
    map<int, int>::iterator getStart(int from) {
        auto res = range.upper_bound(from);
        if(res == begin(range))
            return res;
        if(prev(res)->second >= from)
            return prev(res);
        return res;
    }
    void mergeInterval(int from, int to) {
        if(range.empty()) {
            range[from] = to;
            return;
        }
        
        auto start = getStart(from);
        if(start->first <= from and start->second >= to) return; //in range
        if(start == end(range) or start->first > to) { //can not merge
            range[from] = to;
            return;
        }
        start->second = max(start->second, to);
        auto nxt = next(start);
        while(nxt != end(range) and nxt->first <= start->second) {
            start->second = max(nxt->second, start->second);
            range.erase(nxt);
            nxt = next(start);
        }
        
        if(start->first > from) {
            range[from] = start->second;
            range.erase(start);
        }    
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        for(auto interval : intervals) {
            mergeInterval(interval[0], interval[1]);
        }
        
        vector<vector<int>> res;
        for(auto [from, to] : range) {
            res.push_back({from, to});
        }
        return res;
    }
};