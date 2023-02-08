class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0, res = 0, end = 0;
        for(int i = 0; cur < nums.size() - 1; i++) {
            end = max(end, i + nums[i]);
            if(cur == i) {
                res++;
                cur = end;
            }
        }
        return res;
    }
};