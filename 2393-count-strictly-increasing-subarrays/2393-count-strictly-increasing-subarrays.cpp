class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long res = 0, now = 1;
        nums.push_back(-1);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) now += 1;
            else {
                res += now * (now + 1) / 2;
                now = 1;
            }
        }
        return res;
    }
};