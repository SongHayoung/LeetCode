class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us(begin(nums1), end(nums1));
        vector<int> res;
        for(auto& x : nums2) {
            if(!us.count(x)) continue;
            res.push_back(x);
            us.erase(x);
        }
        return res;
    }
};