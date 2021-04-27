class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        pair<int, int> t{0, INT_MIN}, f{INT_MAX, INT_MIN};
        bool last = true;
        int idx = 1;
        int res = 0;
        for(auto& num : nums) {
            if(num == 0) {
                if(idx == 1) continue;
                last = true;
                idx = 0;
                res = max(res, max(t.second == INT_MIN ? 0 : t.second, f.first == INT_MAX ? 0 : f.second - f.first));
                t = {0, INT_MIN}, f = {INT_MAX, INT_MIN};
            } else {
                if(last) {
                    if(num > 0) t.second = idx;
                    else f.second = idx, f.first = min(f.first, idx);
                    last = num > 0;
                } else {
                    if(num < 0) t.second = idx;
                    else f.second = idx, f.first = min(f.first, idx);
                    last = num < 0;
                }
            }
            idx++;
        }
        return idx != 1 ?
               max(res, max(t.second == INT_MIN ? 0 : t.second, f.first == INT_MAX ? 0 : f.second - f.first)) : res;
    }
};
