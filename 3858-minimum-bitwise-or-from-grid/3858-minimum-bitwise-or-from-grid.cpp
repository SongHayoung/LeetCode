
class Solution {
    pair<vector<vector<int>>,vector<vector<int>>> divide(vector<vector<int>>& A, int b) {
        vector<vector<int>> on, off;
        for(auto& row : A) {
            on.emplace_back();
            off.emplace_back();
            for(auto& n : row) {
                if(n & (1<<b)) {
                    on.back().push_back(n);
                } else off.back().push_back(n);
            }
        }
        return {on,off};
    }
public:
    int minimumOR(vector<vector<int>>& grid) {
        int res = 0;
        auto has = [&](vector<vector<int>>& A) {
            for(auto& row : A) {
                if(row.size() == 0) return false;
            }
            return true;
        };
        for(int b = 17; b >= 0; b--) {
            auto [on,off] = divide(grid,b);
            auto onh = has(on), offh = has(off);
            if(offh) {
                grid = off;
            } else if (!offh) {
                res |= 1<<b;
            }
        }
        return res;
    }
};