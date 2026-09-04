class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        for(auto& n : nums1) freq[n]++;
        for(auto& n : nums2) freq[n]++;
        for(auto& [k,v] : freq) if(v&1) return -1;
        freq = {};
        for(auto& n : nums1) freq[n]++;
        for(auto& n : nums2) freq[n]--;
        int res = 0;
        for(auto& [k,v] : freq) res += abs(v);
        return res / 4;
    }
};
