class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int mi = nums[i] * 1ll - k, ma = nums[i] * 1ll + k;
            if(i) {
                if(nums[i-1] < mi) nums[i] = mi;
                else nums[i] = min(ma, nums[i-1] + 1);
            } else nums[i] = mi;
            
            if(!i or nums[i] != nums[i-1]) res++;
        }
        return res;
    }
};