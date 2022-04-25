#define all(a) begin(a), end(a)

class Solution {
public:
    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int s) {
        sort(all(w));
        sort(all(t));
        int l = 0, r = min(t.size(), w.size());
        while(l <= r) {
            int m = (l + r) >> 1, use = 0;
            multiset<int> ms(end(w) - m, end(w));
            
            for(int i = m - 1; i >= 0; i--) {
                auto wo = prev(end(ms));
                if(*wo < t[i]) {
                    wo = ms.lower_bound(t[i] - s);
                    if(wo == end(ms) or ++use > p) break;
                }
                ms.erase(wo);
            }
            
            if(ms.empty()) l = m + 1;
            else r = m - 1;
        }
        return l - 1;
    }
};