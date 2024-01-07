class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ma = 0, res = 0;
        for(auto& d : dimensions) {
            int dig = d[0] * d[0] + d[1] * d[1];
            if(ma < dig) ma = dig, res = d[0] * d[1];
            else if(ma == dig) res = max(res, d[0] * d[1]);
        }
        return res;
    }
};