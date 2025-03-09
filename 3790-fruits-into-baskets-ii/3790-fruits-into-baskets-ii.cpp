class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = 0;
        vector<int> use(fruits.size());
        for(auto& f : fruits) {
            int at = -1;
            for(int i = 0; i < baskets.size(); i++) {
                if(use[i]) continue;
                if(baskets[i] <= f) continue;
                at = i;
                break;
            }
            if(at == -1) res++;
            else use[at] = 1;
        }
        return res;
    }
};