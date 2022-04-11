class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = nums.size();
        for(int i = 0; i < res;) {
            int last = i;
            for(; last < res and nums[i] == nums[last]; last++) {}
            int dis = last - i - 2;
            if(dis >= 0) {
                for(int j = i + 2; j + dis < res; j++) {
                    nums[j] = nums[j + dis];
                }
                res -= dis;
                last = i + 2;
            }
            i = last;
        }
        return res;
    }
};