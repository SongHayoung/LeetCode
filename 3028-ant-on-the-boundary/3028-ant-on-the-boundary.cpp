class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int res = 0, now = 0;
        for(auto& n : nums) {
            now += n;
            if(now == 0) res += 1;
        }
        return res;
    }
};
