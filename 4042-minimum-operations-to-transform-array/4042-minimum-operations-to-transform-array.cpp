class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long res = LLONG_MAX, base = 0;
        for(int i = 0; i < nums1.size(); i++) base += abs(nums1[i] - nums2[i]);
        
        for(int i = 0; i < nums1.size(); i++) {
            long long now = base - abs(nums1[i] - nums2[i]) + 1;
            int lo = nums2[i], hi = nums2.back();
            if(lo > hi) swap(lo, hi);
            if(lo <= nums1[i] and nums1[i] <= hi) {
                now += abs(nums1[i] - lo) + abs(nums1[i] - hi);
            } else {
                now += max(abs(nums1[i] - lo), abs(nums1[i] - hi));
            }
            res = min(res, now);
        }
        return res;
    }
};