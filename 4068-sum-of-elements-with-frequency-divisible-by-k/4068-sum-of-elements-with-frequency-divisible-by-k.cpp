class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto& n : nums) freq[n]++;
        int res = 0;
        for(auto& [x,v] : freq) if(v % k == 0) res += x * v;
        return res;
    }
};