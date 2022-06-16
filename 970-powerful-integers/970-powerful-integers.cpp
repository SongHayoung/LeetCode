class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound < 2) return {};
        if(x < y) return powerfulIntegers(y, x, bound);
        if(x == 1 and y == 1) return {2};
        if(y == 1) {
            vector<int> res{2};
            int p = 1;
            while(y + pow(x,p) <= bound) {
                res.push_back(y + pow(x, p));
                p++;
            }
            return res;
        }
        unordered_set<int> us;
        int p = 0;
        while(pow(x,p) + 1 <= bound) {
            for(int i = 0, X = pow(x, p); X + pow(y,i) <= bound; i++) {
                us.insert(X + pow(y,i));
            }
            p++;
        }
        
        return vector<int>(begin(us), end(us));
    }
};