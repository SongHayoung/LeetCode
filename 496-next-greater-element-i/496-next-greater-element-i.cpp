class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> st;
        vector<int> greater(nums2.size(), -1);
        unordered_map<int, int> lookup;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            lookup[nums2[i]] = i;
            
            while(!st.empty() and st.back() < nums2[i])
                st.pop_back();
            if(!st.empty())
                greater[i] = st.back();
            
            st.push_back(nums2[i]);
        }
        
        vector<int> res;
        for(auto n : nums1) {
            res.push_back(greater[lookup[n]]);
        }
        return res;
    }
};