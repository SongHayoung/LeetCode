class Solution {
    int dp[500][500];
    int dfs(unordered_map<int,vector<int>>& um1, unordered_map<int,vector<int>>& um2, vector<int>& n1, vector<int>& n2, int i, int j) {
        if(i == n1.size() or j == n2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 0;
        auto um2it = lower_bound(um2[n1[i]].begin(),um2[n1[i]].end(), j);
        if(um2it != um2[n1[i]].end()) {
            dp[i][j] = max(dp[i][j], dfs(um1, um2, n1, n2, i + 1, *um2it + 1) + 1);
        }
        
        auto um1it = lower_bound(um1[n2[j]].begin(), um1[n2[j]].end(), i);
        if(um1it != um1[n2[j]].end()) {
            dp[i][j] = max(dp[i][j], dfs(um1, um2, n1, n2, *um1it + 1, j + 1) + 1);
        }
        
        return dp[i][j] = max(dp[i][j], dfs(um1, um2, n1,n2,i+1,j+1));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        unordered_map<int,vector<int>> n1, n2;
        for(int i = 0; i < nums1.size(); i++) n1[nums1[i]].push_back(i);
        for(int i = 0; i < nums2.size(); i++) n2[nums2[i]].push_back(i);
        return dfs(n1,n2,nums1,nums2,0,0);
    }
};