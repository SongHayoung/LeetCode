class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(*min_element(begin(nums1),end(nums1)) & 1) return true;
        for(auto& n : nums1) if(n&1) return false;
        return true;
    }
};
