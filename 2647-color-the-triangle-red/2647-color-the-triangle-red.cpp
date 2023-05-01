class Solution {
public:
    vector<vector<int>> colorRed(int n) {
        vector<vector<int>> res;
        for(int i = n; i >= 1; i--) {
            int d = (n - i) % 4;
            if(d == 0) for(int j = 2 * i - 1; j > 0; j -= 2) res.push_back({i,j});
            else if(d == 1) {
                if(2 <= i) res.push_back({i,2});
            } else if(d == 2) for(int j = 2 * i - 1; j > 2; j -= 2) res.push_back({i,j});
            else res.push_back({i,1});
            if(i == 1 and 1 <= d and d <= 2) res.push_back({1,1});
        }
        return res;
    }
};