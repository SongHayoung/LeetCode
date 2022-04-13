class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        int res = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            if(counter[nums[r]]++ == 0) k--;
            while(k < 0) {
                if(counter[nums[l]]-- == 1)
                    k++;
                l++;
            }
            res += r - l;
        }
        return res;
    }
};