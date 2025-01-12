const int _mutable = 0;
const int _lo = 1;
const int _lc = 2;

class Solution {
    unordered_map<int, set<int>> init(string& s, string& l, int& len) {
        unordered_map<int, set<int>> res;
        for(int i = 0; i < len; i++) {
            if(l[i] == '0') {
                res[_mutable].insert(i);
            } else {
                res[s[i] == '(' ? _lo : _lc].insert(i);
            }
        }

        vector<int> rm;
        for(auto lo = res[_lo].rbegin(); lo != res[_lo].rend(); lo++) {
            auto bound = res[_lc].upper_bound(*lo);
            if(bound != res[_lc].end()) {
                res[_lc].erase(bound);
                rm.push_back(*lo);
            }
        }

        for(auto& r : rm) {
            res[_lo].erase(r);
        }

        return res;
    }
public:
    bool canBeValid(string s, string locked) {
        int len(s.length());
        if(len & 1) return false;
        unordered_map<int, set<int>> m = init(s, locked, len);
        for(auto lo = m[_lo].rbegin(); lo != m[_lo].rend(); lo++) {
            auto bound = m[_mutable].upper_bound(*lo);
            if(bound == m[_mutable].end()) return false;
            m[_mutable].erase(bound);
        }
        for(auto& lc : m[_lc]) {
            auto bound = m[_mutable].upper_bound(lc);
            if(bound == m[_mutable].begin()) return false;
            m[_mutable].erase(prev(bound));
        }
        return true;
    }
};