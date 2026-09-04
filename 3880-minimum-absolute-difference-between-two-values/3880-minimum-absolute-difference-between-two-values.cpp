
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        unordered_map<int,vector<int>> at;
        for(int i = 0; i < nums.size(); i++) at[nums[i]].push_back(i);
        int res = INT_MAX, i = 0, j = 0, n = at[1].size(), m = at[2].size();
        for(int i = 0; i < n; i++) {
            while(j < m and at[2][j] <= at[1][i]) j++;
            if(j != m) {
                res = min(res, at[2][j] - at[1][i]);
            }
            if(j) {
                res = min(res, at[1][i] - at[2][j-1]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};