class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int score[2]{0,0}, run = 0;
        for(int i = 0, game = 1; i < nums.size(); i++, game++) {
            if(nums[i] & 1) run = !run;
            if(game % 6 == 0) run = !run;
            score[run] += nums[i];
        }
        return score[0] - score[1];
    }
};