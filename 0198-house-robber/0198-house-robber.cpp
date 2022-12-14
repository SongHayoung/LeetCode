class Solution {
public:
    int rob(vector<int>& nums) {
        int odd = 0, even = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i&1) odd = max(even, odd + nums[i]);
            else even = max(odd, even + nums[i]);
        }
        return max(odd,even);
    }
};