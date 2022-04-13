class Solution {
    int dp[100002][2];
    int helper(vector<int>& n1, vector<int>& n2, bool sw, int p) {
        if(p + 1 == n1.size()) return 0;
        if(dp[p][sw] != -1) return dp[p][sw];
        int& res = dp[p][sw] = 987654321;
        if(n1[p] < n1[p+1] and n2[p] < n2[p+1]) {
            res = min(res, helper(n1, n2, false, p+1));
        }
        if(n1[p] < n2[p+1] and n2[p] < n1[p+1]) {
            swap(n2[p+1], n1[p+1]);
            res = min(res, helper(n1, n2, true, p+1) + 1);
            swap(n2[p+1], n1[p+1]);
        }
        return res;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        vector<int> v1{-1}, v2{-1};
        v1.insert(v1.end(), nums1.begin(), nums1.end());
        v2.insert(v2.end(), nums2.begin(), nums2.end());
        return helper(v1,v2,false,0);
    }
};