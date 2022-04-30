class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int res(0), mod(1e9 + 7), diff(INT_MIN);
        vector<int> sortedNums1(begin(nums1), end(nums1));
        sort(begin(sortedNums1), end(sortedNums1));
        for(int i = 0; i < nums1.size(); i++) {
            int absolute = abs(nums1[i] - nums2[i]), change(INT_MAX);
            res = (res + absolute) % mod;
            auto it = lower_bound(begin(sortedNums1), end(sortedNums1), nums2[i]);
            if(it != end(sortedNums1)) {
                change = min(change, abs(*it - nums2[i]));
            }
            if(it != begin(sortedNums1)) {
                change = min(change, abs(*(prev(it)) - nums2[i]));
            }
            diff = max(diff, abs(absolute - change));
        }
        
        res -= diff;
        return res < 0 ? res + mod : res;
    }
};
