
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        set<int> res;
        for(int i = 0; i < n; i++)
            res.insert(i);

        for(int i = 0; i < n; i++) {
            list<int> removes;
            for(auto& cell : res) {
                if(knows(i, cell)) continue;
                res.erase(cell);
            }
        }
        
        for(auto& cell : res) {
            for(int i = 0; i < n; i++) {
                if(i == cell) continue;
                if(knows(cell, i)) {
                    res.erase(cell);
                    break;
                }
            }
        }

        return res.empty() ? -1 : *res.lower_bound(0);
    }
};
