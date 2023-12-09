class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> A(begin(nums1), end(nums1)), B(begin(nums2), end(nums2));
        vector<int> res{0,0};
        for(int i = 0; i < nums1.size(); i++) {
            if(B.count(nums1[i])) res[0] += 1;
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(A.count(nums2[i])) res[1] += 1;
        }
        return res;
    }
};