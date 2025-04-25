class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int sum = 0;
        long long res = 0;
        unordered_map<int, int> freq{{0,1}};
        for(int i = 0; i < nums.size(); i++) {
            sum = sum + ((nums[i] % modulo) == k);
            sum %= modulo;
            res += freq[(sum - k + modulo) % modulo];
            freq[sum] += 1;
        }
        return res;
    }
};