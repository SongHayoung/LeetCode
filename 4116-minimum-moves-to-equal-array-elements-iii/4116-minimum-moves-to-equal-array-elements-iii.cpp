class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ma = 0, res = 0;
        for(auto& n : nums) {
            ma = max(ma, n);
            res += ma - n;
        }
        return res;
    }
};