class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ma = 0;
        for(auto& x : nums) freq[x] += 1;
        for(auto& [k,v] : freq) ma = max(ma,v);
        int res = 0;
        for(auto& [k,v] : freq) if(v == ma) res += 1;
        return res * ma;
    }
};
