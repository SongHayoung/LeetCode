class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        int res = 0;
        for(auto& n : nums) {
            res += freq[n];
            freq[n] += 1;
        }
        return res;
    }
};