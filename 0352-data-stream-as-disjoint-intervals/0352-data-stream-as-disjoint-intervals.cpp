class SummaryRanges {
    map<int, int> range;
public:
    SummaryRanges() {}
    
    void addNum(int val) {
        if(range.empty()) {
            range[val] = val;
            return;
        }
        auto lower = range.lower_bound(val);
        if(lower->first == val) return;
        if(lower != begin(range)) {
            auto prv = prev(lower);
            if(prv->second >= val) return;
            else if(prv->second == val - 1) {
                prv->second = val;
                if(lower->first == val + 1) {
                    prv->second = lower->second;
                    range.erase(lower);
                }
                return;
            }
        }
        if(lower != end(range)) {
            if(lower->first == val + 1) {
                range[val] = lower->second;
                range.erase(lower);
                return;
            } else {
                range[val] = val;
            }
        } else {
            range[val] = val;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto [f, t] : range) {
            res.push_back({f,t});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */