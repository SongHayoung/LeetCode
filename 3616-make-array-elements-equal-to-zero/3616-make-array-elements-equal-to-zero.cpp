class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ri = accumulate(begin(nums), end(nums), 0), le = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(!nums[i]) {
                if(le == ri) res += 2;
                else if(abs(le-ri) == 1) res += 1;
            }
            le += nums[i], ri -= nums[i];
            if(le > ri + 1) return res;
        }
        return res;
    }
};