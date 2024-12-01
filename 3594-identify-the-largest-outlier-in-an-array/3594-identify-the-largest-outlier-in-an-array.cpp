class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        unordered_map<int,int> f;
        int res = INT_MIN;
        for(auto& n : nums) f[n]++;
        for(auto& [k1,v1] : f) {
            for(auto& [k2,v2] : f) {
                if(k1 == k2 and v1 == 1) continue;
                int s = sum - k1 - k2;
                if(k1 == s) {
                    res = max(res, k2);
                }
                if(k2 == s) {
                    res = max(res, k1);
                }
            }
        }
        return res;
    }
};