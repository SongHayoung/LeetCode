class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> freq;
        int n = wall.size(), res = n;
        for(auto& row : wall) {
            for(int i = 0, psum = 0; i < row.size() - 1; i ++) {
                res = min(res, n - ++freq[psum += row[i]]);
            }
        }
        return res;
    }
};