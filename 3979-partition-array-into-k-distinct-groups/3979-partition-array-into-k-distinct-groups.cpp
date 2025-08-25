class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int ma = 0, n = nums.size();
        if(n % k) return false;
        for(auto& n : nums) {
            ma = max(ma, ++freq[n]);
        }
        return ma <= n / k;
    }
};