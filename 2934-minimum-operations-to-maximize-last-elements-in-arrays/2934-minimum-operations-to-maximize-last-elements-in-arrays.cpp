class Solution {
    int helper(vector<int>& A, vector<int>& B) {
        int n = A.size(), ma1 = A.back(), ma2 = B.back();
        int res = 0;
        for(int i = 0; i < n-1; i++) {
            if(A[i] <= ma1 and B[i] <= ma2) continue;
            if(A[i] <= ma2 and B[i] <= ma1) res += 1;
            else return 3 * n;
        }
        return res;
    }
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int res = helper(nums1, nums2), n = nums1.size();
        swap(nums1[n-1], nums2[n-1]);
        res = min(res, 1 + helper(nums1,nums2));
        if(res > 2 * n) return -1;
        return res;
    }
};

