class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i = 0; i < m and j < n; i++) {
            if(nums1[i] < nums2[j]) continue;
            for(int k = m; k > i; k--) {
                nums1[k] = nums1[k-1];
            }
            nums1[i] = nums2[j];
            j++;
            m++;
        }
        for(; j < n; j++) {
            nums1[m] = nums2[j];
            m++;
        }
    }
};