class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        long long sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > 0) res += 1;
            else break;
        }
        return res;
    }
};
