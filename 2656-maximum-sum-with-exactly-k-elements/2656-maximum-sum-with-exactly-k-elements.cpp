
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int res = 0;
        int ma = *max_element(begin(nums), end(nums));
        for(int i = 0; i < k; i++) {
            res += ma;
            ma += 1;
        }
        return res;
    }
};
