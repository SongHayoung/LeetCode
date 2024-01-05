class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis{INT_MIN};
        for(auto n : nums) {
            if(lis.back() < n) {
                lis.push_back(n);
            } else {
                auto it = lower_bound(lis.begin(), lis.end(), n);
                *it = n;
            }
        }
        return lis.size() - 1;
    }
};