class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, pre = 0;
        vector<int> freq(51);
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]] = max(freq[nums[i]], pre) + 1;
            res = max(res + (nums[i] == k), freq[nums[i]]);
            pre += (nums[i] == k);
        }
        return res;
    }
};