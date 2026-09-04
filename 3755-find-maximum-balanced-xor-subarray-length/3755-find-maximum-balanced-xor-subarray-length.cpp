class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        unordered_map<int,unordered_map<int,int>> at;
        at[0][0] = -1;
        int bit = 0, res = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            bit ^= nums[i];
            if(nums[i] % 2 == 0) cnt++;
            else cnt--;
            
            if(at[bit].count(cnt)) res = max(res, i - at[bit][cnt]);
            else at[bit][cnt] = i;
        }
        return res;
    }
};
