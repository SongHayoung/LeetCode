class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> p(people.begin(), people.end());
        int res = 0;
        while(!p.empty()) {
            auto ma = prev(end(p));
            int mi = limit - *ma;
            p.erase(ma);
            if(mi != 0) {
                auto it = p.upper_bound(mi);
                if(it != begin(p)) {
                    p.erase(prev(it));
                }
            }
            res++;
        }
        return res;
    }
};