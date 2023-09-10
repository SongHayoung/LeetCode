class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> cov(111);
        for(auto n : nums) {
            cov[n[0]] += 1;
            cov[n[1] + 1] -= 1;
        }
        int res = 0;
        for(int i = 1; i < cov.size(); i++) {
            cov[i] += cov[i-1];
            if(cov[i] > 0) res += 1;
        }
        return res;
    }
};