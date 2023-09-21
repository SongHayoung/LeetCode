class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n, mid = (n + m) / 2;
        while(l <= r) {
            int i = l + (r - l) / 2;
            int j = mid - i;
            if(i > 0 and nums1[i-1] > nums2[j]) {
                r = i - 1;
            } else if(i < n and nums1[i] < nums2[j-1]) {
                l = i + 1;
            } else {
                int right = (i == n) ? nums2[j] : (j == m) ? nums1[i] : min(nums1[i], nums2[j]);
                if((n + m) & 1) return right;
                int left = (i == 0) ? nums2[j - 1] : (j == 0) ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]);
                return (left + right) / 2.0;
            }
        }
        return -1;
    }
};