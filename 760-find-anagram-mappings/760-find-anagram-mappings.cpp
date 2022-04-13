class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums2[i]].push_back(i);
        }
        
        vector<int> res(n);
        for(int i = 0 ; i < n; i++) {
            int index = mp[nums1[i]].back();
            mp[nums1[i]].pop_back();
            res[i] = index;
        }
        return res;
    }
};