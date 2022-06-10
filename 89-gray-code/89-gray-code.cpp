class Solution {
    bool helper(vector<int>& res, int& n, unordered_set<int>& us) {
        if(res.size() == 1<<n) return true;
        else {
            int last = res.back();
            for(int i = 0; i < n; i++) {
                bool bit = (last & (1<<i));
                int next = last + (bit ? -(1<<i) : (1<<i));
                if(us.count(next)) continue;
                res.push_back(next);
                us.insert(next);
                if(helper(res, n, us)) return true;
                res.pop_back();
                us.erase(next);
            }
        }
        return false;
    }
public:
    vector<int> grayCode(int n) {
        int mask = (1<<n) - 1;
        unordered_set<int> us{0};
        vector<int> res{0};
        helper(res, n, us);
        return res;
    }
};