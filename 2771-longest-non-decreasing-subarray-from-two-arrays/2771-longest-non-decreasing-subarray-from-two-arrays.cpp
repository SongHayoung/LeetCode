class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        pair<long long, long long> dp1{0,0}, dp2{0,0};
        long long res = 0;
        for(int i = 0; i < nums1.size(); i++) {
            int a = nums1[i], b = nums2[i];
            pair<long long, long long> dpp1{a,1}, dpp2{b,1};
            if(dpp1.first >= dp1.first) {
                dpp1.second = max(dpp1.second, dp1.second + 1);
            }
            if(dpp1.first >= dp2.first) {
                dpp1.second = max(dpp1.second, dp2.second + 1);
            }
            if(dpp2.first >= dp1.first) {
                dpp2.second = max(dpp2.second, dp1.second + 1);
            }
            if(dpp2.first >= dp2.first) {
                dpp2.second = max(dpp2.second, dp2.second + 1);
            }
            res = max({res, dpp1.second, dpp2.second});
            swap(dp1,dpp1);
            swap(dp2,dpp2);
        }
        return res;
    }
};
