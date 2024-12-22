class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        bitset<101> freq;
        for(int i = n - 1; i >= 0; i--) {
            freq[nums[i]].flip();
            if(!freq[nums[i]]) return i/3 + 1;
        }
        return 0;
    }
};