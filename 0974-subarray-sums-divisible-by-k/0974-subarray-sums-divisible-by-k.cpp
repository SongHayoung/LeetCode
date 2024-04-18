class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;
        int sum = 0, res = 0;
        for(auto& n : nums) {
            sum = (sum + n % k + k) % k;
            res += freq[sum]++;
        }
        return res;
    }
};