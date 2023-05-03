class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us1(begin(nums1), end(nums1));
        unordered_set<int> us2(begin(nums2), end(nums2));
        vector<int> res1, res2;
        for(auto n : nums1) if(!us2.count(n)) res1.push_back(n), us2.insert(n);
        for(auto n : nums2) if(!us1.count(n)) res2.push_back(n), us1.insert(n);
        return {res1,res2};
    }
};