class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> root(n);
        for(int i = 1; i < n; i++) root[i] = nums[i] <= nums[i-1] + maxDiff ? root[i-1] : i;
        vector<bool> res(queries.size());
        for(int i = 0; i < queries.size(); i++) res[i] = root[queries[i][0]] == root[queries[i][1]];
        return res;
    }
};