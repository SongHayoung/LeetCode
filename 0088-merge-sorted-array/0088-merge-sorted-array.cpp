class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n + m;
        for(int i = m - 1, j = k - 1; i >= 0; i--,j--) {
            nums1[j] = nums1[i];
        }
        for(int p = 0, i = n, j = 0; j < n; p++) {
            if(i == k) {
                nums1[p] = nums2[j++];
            } else {
                if(nums1[i] < nums2[j]) {
                    nums1[p] = nums1[i++];
                } else nums1[p] = nums2[j++];
            }
        }
    }
};