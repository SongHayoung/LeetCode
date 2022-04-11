class Solution {
    map<int, pair<int,int>> range;
    
    map<int, pair<int,int>>::iterator getStart(int start, int len) {
        auto it = range.lower_bound(start);
        if(it != begin(range)) {
            auto prv = prev(it);
            if(prv->first + prv->second.first > start)
                return prv;
        }
        if(it->first < start + len)
            return it;
        return end(range);
    }
    
    int getStackHeight(map<int, pair<int,int>>::iterator it, int start, int len) {
        int h = 0;
        for(; it != end(range) and it->first < start + len; it++) {
            h = max(h, it->second.second);
        }
        return h;
    }
    
    void removeHeight(map<int, pair<int,int>>::iterator it, int start, int len) {
        vector<map<int, pair<int,int>>::iterator> rm;
        for(; it != end(range) and it->first < start + len; it++) {
            if(it->first < start) {
                if(it->first + it->second.first > start + len) {
                    range[start+len] = {it->first + it->second.first - start - len, it->second.second};
                }
                it->second.first = start;
            } else {
                if(it->first + it->second.first <= start + len) {
                    rm.push_back(it);
                } else {
                    range[start+len] = {it->first + it->second.first - start - len, it->second.second};
                    rm.push_back(it);
                }
            }
        }
        while(!rm.empty()) {
            range.erase(rm.back());
            rm.pop_back();
        }
    }
    
    int addRange(int start, int len) {
        auto startIt = getStart(start, len);
        int h = getStackHeight(startIt, start, len);
        removeHeight(startIt, start, len);
        range[start] = {len, h + len};
        
        return h + len;
    }
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> res;
        for(auto p : positions) {
            int h = addRange(p[0], p[1]);
            if(res.empty() or res.back() < h)
                res.push_back(h);
            else
                res.push_back(res.back());
        }
        return res;
    }
};