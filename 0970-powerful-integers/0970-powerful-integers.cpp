class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(x == 1 and y == 1) {
            if(bound < 2) return {};
            return {2};
        }
        unordered_set<int> res;
        for(int i = 1; i <= bound; i *= x) {
            for(int j = 1; j + i <= bound; j *= y) {
                res.insert(i+j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(begin(res), end(res));
    }
};